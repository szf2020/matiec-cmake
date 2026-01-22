#pragma once

#include "absyntax/absyntax.hh"
#include "absyntax_utils/absyntax_utils.hh"
#include "stage1_2/stage1_2.hh"

#include <memory>

namespace matiec::internal {

// Owns the compilation AST roots and cleans up global per-compilation state.
// The compiler pipeline still uses raw pointers, but this guard guarantees
// cleanup on all exit paths (including early returns/exceptions).
struct ast_roots_deleter {
    ::symbol_c* ordered_root = nullptr;

    void operator()(::symbol_c* tree_root) const noexcept {
        matiec::ast_delete(tree_root, ordered_root);
    }
};

class compilation_cleanup_guard final {
public:
    compilation_cleanup_guard() = default;
    compilation_cleanup_guard(const compilation_cleanup_guard&) = delete;
    compilation_cleanup_guard& operator=(const compilation_cleanup_guard&) = delete;

    ~compilation_cleanup_guard() noexcept {
        // These global tables store raw pointers into the AST; clear them before
        // freeing the compilation's AST.
        ::absyntax_utils_reset();

        // Always run ast_delete(), even if we never got a root pointer back, so
        // any heap-tracked symbols are released.
        const auto deleter = tree_root_.get_deleter();
        ::symbol_c* root = tree_root_.release();
        deleter(root);

        // Release lexer-owned strings used by tokens/filenames.
        matiec::cstr_pool_clear();

        // Clear stage1_2 lexer/parser symbol tables and flags for the next run.
        ::stage1_2_reset();
    }

    std::unique_ptr<::symbol_c, ast_roots_deleter>& tree_root_owner() noexcept {
        return tree_root_;
    }

private:
    std::unique_ptr<::symbol_c, ast_roots_deleter> tree_root_{nullptr, ast_roots_deleter{nullptr}};
};

} // namespace matiec::internal

