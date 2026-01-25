<p align="center">
  <h1 align="center">matiec</h1>
  <p align="center">
    <strong>IEC 61131-3 Compiler</strong><br>
    <em>Convert PLC code (ST/IL/SFC) to ANSI C</em>
  </p>
  <p align="center">
    <a href="#english">English</a> | <a href="#中文">中文</a>
  </p>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/license-GPL--3.0-blue.svg" alt="License">
  <img src="https://img.shields.io/badge/C%2B%2B-11-brightgreen.svg" alt="C++ Standard">
  <img src="https://img.shields.io/badge/CMake-3.16+-orange.svg" alt="CMake">
  <img src="https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg" alt="Platform">
</p>

---

<a name="english"></a>

## English

### Overview

**matiec** is an open-source compiler for IEC 61131-3 programming languages, widely used in industrial automation and PLC (Programmable Logic Controller) programming.

The compiler translates IEC 61131-3 textual languages into ANSI C code, which can then be compiled for any target platform.

### Features

- **Full IEC 61131-3 Support**: ST (Structured Text), IL (Instruction List), SFC (Sequential Function Chart)
- **Cross-Platform**: Windows, Linux, macOS
- **Modern Build System**: CMake-based, easy integration
- **Package Manager Ready**: CPM.cmake, vcpkg, FetchContent support
- **Complete Standard Library**: Timers, counters, arithmetic, type conversions

### Quick Start

#### Prerequisites

| Platform | Command |
|----------|---------|
| Windows | `choco install winflexbison3` |
| macOS | `brew install flex bison` |
| Linux | `apt install flex bison` |

#### Build from Source

```bash
git clone https://github.com/lusipad/matiec-cmake.git
cd matiec-cmake
cmake -B build
cmake --build build
```

#### Basic Usage

```bash
# Compile IEC to C
./build/iec2c -I lib -T output/ your_program.st

# Normalize IEC code (for debugging)
./build/iec2iec your_program.st
```

### Command Line Options

| Option | Description |
|--------|-------------|
| `-I <dir>` | Include directory for libraries |
| `-T <dir>` | Target directory for output |
| `-h` | Display help |
| `-v` | Display version |
| `-f` | Display full token location |
| `-p` | Allow forward references |
| `-l` | Relaxed datatype equivalence |
| `-s` | Enable SAFE datatypes (PLCopen Safety) |
| `-n` | Allow nested comments |
| `-r` | Enable REF_TO, REF, ^, NULL extensions |

### Integration

#### CPM.cmake (Recommended)

```cmake
include(cmake/CPM.cmake)

CPMAddPackage(
    NAME matiec
    GITHUB_REPOSITORY lusipad/matiec-cmake
    GIT_TAG master
)

# Compile IEC source
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/program.c
    COMMAND iec2c -I ${MATIEC_LIB_DIR} -T ${CMAKE_BINARY_DIR} program.st
    DEPENDS iec2c program.st
)
```

#### FetchContent

```cmake
include(FetchContent)
FetchContent_Declare(matiec
    GIT_REPOSITORY https://github.com/lusipad/matiec-cmake.git
    GIT_TAG master
)
FetchContent_MakeAvailable(matiec)
```

#### vcpkg

```bash
vcpkg install matiec --overlay-ports=./tools/vcpkg-port
```

See [docs/INTEGRATION.md](docs/INTEGRATION.md) for detailed integration guide.

### Exported CMake Variables

When included as a subdirectory:

| Variable | Description |
|----------|-------------|
| `MATIEC_LIB_DIR` | Path to standard library |
| `MATIEC_IEC2C_EXECUTABLE` | Path to iec2c executable |
| `MATIEC_IEC2IEC_EXECUTABLE` | Path to iec2iec executable |

### Project Structure

```
matiec-cmake/
├── src/
│   ├── absyntax/          # Abstract syntax tree definitions
│   ├── absyntax_utils/    # AST utilities
│   ├── stage1_2/          # Lexer (Flex) & Parser (Bison)
│   ├── stage3/            # Semantic analysis
│   ├── stage4/
│   │   ├── generate_c/    # C code generator (iec2c)
│   │   └── generate_iec/  # IEC normalizer (iec2iec)
│   ├── lib/               # IEC 61131-3 standard library
│   │   ├── C/             # C runtime headers
│   │   └── *.txt          # IEC library definitions
│   └── include/           # Public headers
├── docs/                  # Documentation
├── cmake/                 # CMake modules
├── config/                # Config templates
├── tests/                 # Tests
├── tools/                 # Tooling and ports
│   ├── vcpkg-port/
│   └── issues/
└── openspec/              # OpenSpec specs/changes
```

### Supported IEC 61131-3 Languages

| Language | Type | Support |
|----------|------|---------|
| **ST** (Structured Text) | Textual | Full |
| **IL** (Instruction List) | Textual | Full |
| **SFC** (Sequential Function Chart) | Graphical/Textual | Full |
| **FBD** (Function Block Diagram) | Graphical | Partial |
| **LD** (Ladder Diagram) | Graphical | Partial |

### License

This project is licensed under the **GPL-3.0** License. See [COPYING](COPYING) for details.

### Credits

- **Original Author**: Mario de Sousa (msousa@fe.up.pt)
- **CMake Migration**: Community contributors
- Based on IEC 61131-3, 2nd Edition (2001-12-10)

---

<a name="中文"></a>

## 中文

### 概述

**matiec** 是一个开源的 IEC 61131-3 编译器，广泛应用于工业自动化和 PLC（可编程逻辑控制器）编程领域。

该编译器将 IEC 61131-3 文本语言转换为 ANSI C 代码，生成的 C 代码可以在任意目标平台上编译运行。

### 特性

- **完整的 IEC 61131-3 支持**：ST（结构化文本）、IL（指令列表）、SFC（顺序功能图）
- **跨平台**：Windows、Linux、macOS
- **现代构建系统**：基于 CMake，易于集成
- **包管理器支持**：CPM.cmake、vcpkg、FetchContent
- **完整标准库**：定时器、计数器、算术运算、类型转换

### 快速开始

#### 前置依赖

| 平台 | 安装命令 |
|------|----------|
| Windows | `choco install winflexbison3` |
| macOS | `brew install flex bison` |
| Linux | `apt install flex bison` |

#### 从源码构建

```bash
git clone https://github.com/lusipad/matiec-cmake.git
cd matiec-cmake
cmake -B build
cmake --build build
```

#### 基本用法

```bash
# 将 IEC 代码编译为 C
./build/iec2c -I lib -T output/ your_program.st

# 规范化 IEC 代码（用于调试）
./build/iec2iec your_program.st
```

### 命令行选项

| 选项 | 说明 |
|------|------|
| `-I <目录>` | 库文件包含目录 |
| `-T <目录>` | 输出目标目录 |
| `-h` | 显示帮助 |
| `-v` | 显示版本 |
| `-f` | 显示完整的标记位置 |
| `-p` | 允许前向引用 |
| `-l` | 宽松的数据类型等价模型 |
| `-s` | 启用 SAFE 数据类型（PLCopen Safety） |
| `-n` | 允许嵌套注释 |
| `-r` | 启用 REF_TO、REF、^、NULL 扩展 |

### 集成到您的项目

#### CPM.cmake（推荐）

```cmake
include(cmake/CPM.cmake)

CPMAddPackage(
    NAME matiec
    GITHUB_REPOSITORY lusipad/matiec-cmake
    GIT_TAG master
)

# 编译 IEC 源码
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/program.c
    COMMAND iec2c -I ${MATIEC_LIB_DIR} -T ${CMAKE_BINARY_DIR} program.st
    DEPENDS iec2c program.st
)
```

#### FetchContent

```cmake
include(FetchContent)
FetchContent_Declare(matiec
    GIT_REPOSITORY https://github.com/lusipad/matiec-cmake.git
    GIT_TAG master
)
FetchContent_MakeAvailable(matiec)
```

#### vcpkg

```bash
vcpkg install matiec --overlay-ports=./tools/vcpkg-port
```

详细集成指南请参阅 [docs/INTEGRATION.md](docs/INTEGRATION.md)。

### 导出的 CMake 变量

当作为子目录包含时，以下变量可用：

| 变量 | 说明 |
|------|------|
| `MATIEC_LIB_DIR` | 标准库路径 |
| `MATIEC_IEC2C_EXECUTABLE` | iec2c 可执行文件路径 |
| `MATIEC_IEC2IEC_EXECUTABLE` | iec2iec 可执行文件路径 |

### 项目结构

```
matiec-cmake/
├── src/
│   ├── absyntax/          # 抽象语法树定义
│   ├── absyntax_utils/    # AST 工具库
│   ├── stage1_2/          # 词法分析器 (Flex) & 语法分析器 (Bison)
│   ├── stage3/            # 语义分析
│   ├── stage4/
│   │   ├── generate_c/    # C 代码生成器 (iec2c)
│   │   └── generate_iec/  # IEC 规范化器 (iec2iec)
│   ├── lib/               # IEC 61131-3 标准库
│   │   ├── C/             # C 运行时头文件
│   │   └── *.txt          # IEC 库定义
│   └── include/           # 公共头文件
├── docs/                  # 文档
├── cmake/                 # CMake 模块
├── config/                # 配置模板
├── tests/                 # 测试
├── tools/                 # 工具与端口
│   ├── vcpkg-port/
│   └── issues/
└── openspec/              # OpenSpec 规范/变更
```

### 支持的 IEC 61131-3 语言

| 语言 | 类型 | 支持程度 |
|------|------|----------|
| **ST**（结构化文本） | 文本 | 完整 |
| **IL**（指令列表） | 文本 | 完整 |
| **SFC**（顺序功能图） | 图形/文本 | 完整 |
| **FBD**（功能块图） | 图形 | 部分 |
| **LD**（梯形图） | 图形 | 部分 |

### 编译器架构

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│   Stage 1   │───▶│   Stage 2   │───▶│   Stage 3   │───▶│   Stage 4   │
│   词法分析   │    │   语法分析   │    │   语义分析   │    │   代码生成   │
│   (Flex)    │    │   (Bison)   │    │  类型检查    │    │  C / IEC    │
└─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘
```

### 许可证

本项目采用 **GPL-3.0** 许可证。详见 [COPYING](COPYING)。

### 致谢

- **原作者**：Mario de Sousa (msousa@fe.up.pt)
- **CMake 迁移**：社区贡献者
- 基于 IEC 61131-3 第二版（2001-12-10）

---

<p align="center">
  <sub>Made with care for the PLC community</sub>
</p>
