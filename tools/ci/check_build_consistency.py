#!/usr/bin/env python3
"""Validate key CMake option combinations used by modernization gates."""

from __future__ import annotations

import platform
import shutil
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


@dataclass(frozen=True)
class Profile:
    name: str
    cmake_args: tuple[str, ...]
    cache_expectations: tuple[tuple[str, str], ...]
    smoke_targets: tuple[str, ...]


def run(cmd: list[str], cwd: Path) -> None:
    print(f"[run] {' '.join(cmd)}")
    subprocess.run(cmd, cwd=cwd, check=True)


def parse_cache(cache_path: Path) -> dict[str, str]:
    entries: dict[str, str] = {}
    for raw_line in cache_path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("//") or line.startswith("#"):
            continue
        if "=" not in line or ":" not in line:
            continue
        key_type, value = line.split("=", 1)
        key, _type = key_type.split(":", 1)
        entries[key] = value
    return entries


def verify_cache(cache: dict[str, str], expectations: Iterable[tuple[str, str]], profile: str) -> None:
    for key, expected in expectations:
        actual = cache.get(key)
        if actual != expected:
            raise RuntimeError(
                f"[{profile}] cache mismatch for {key}: expected '{expected}', got '{actual}'"
            )


def main() -> int:
    repo_root = Path(__file__).resolve().parents[2]
    work_root = repo_root / "build-consistency"
    work_root.mkdir(exist_ok=True)

    is_windows = platform.system() == "Windows"
    if is_windows:
        generator_args = ["-G", "Visual Studio 17 2022", "-A", "x64"]
        build_base_cmd = ["cmake", "--build"]
        build_config_args = ["--config", "Release"]
    else:
        generator_args = ["-G", "Ninja"]
        build_base_cmd = ["cmake", "--build"]
        build_config_args = []

    profiles = (
        Profile(
            name="static-only",
            cmake_args=(
                "-DMATIEC_BUILD_SHARED=OFF",
                "-DMATIEC_BUILD_STATIC=ON",
                "-DMATIEC_BUILD_TOOLS=OFF",
                "-DMATIEC_BUILD_TESTS=OFF",
                "-DMATIEC_INSTALL=OFF",
            ),
            cache_expectations=(
                ("MATIEC_BUILD_SHARED", "OFF"),
                ("MATIEC_BUILD_STATIC", "ON"),
                ("MATIEC_BUILD_TOOLS", "OFF"),
                ("MATIEC_BUILD_TESTS", "OFF"),
            ),
            smoke_targets=("matiec_static",),
        ),
        Profile(
            name="shared-tools",
            cmake_args=(
                "-DMATIEC_BUILD_SHARED=ON",
                "-DMATIEC_BUILD_STATIC=OFF",
                "-DMATIEC_BUILD_TOOLS=ON",
                "-DMATIEC_BUILD_TESTS=OFF",
                "-DMATIEC_INSTALL=OFF",
            ),
            cache_expectations=(
                ("MATIEC_BUILD_SHARED", "ON"),
                ("MATIEC_BUILD_STATIC", "OFF"),
                ("MATIEC_BUILD_TOOLS", "ON"),
                ("MATIEC_BUILD_TESTS", "OFF"),
            ),
            smoke_targets=("matiec_shared", "iec2c", "iec2iec"),
        ),
    )

    for profile in profiles:
        build_dir = work_root / profile.name
        if build_dir.exists():
            shutil.rmtree(build_dir)

        configure_cmd = [
            "cmake",
            "-S",
            str(repo_root),
            "-B",
            str(build_dir),
            *generator_args,
            *profile.cmake_args,
        ]
        run(configure_cmd, cwd=repo_root)

        cache = parse_cache(build_dir / "CMakeCache.txt")
        verify_cache(cache, profile.cache_expectations, profile.name)

        for target in profile.smoke_targets:
            run([*build_base_cmd, str(build_dir), *build_config_args, "--target", target], cwd=repo_root)

    print("[ok] build consistency profiles passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
