# Contributing to CoManage

Thank you for your interest in contributing! This is primarily a portfolio/learning project, but improvements and suggestions are always welcome.

## 🤝 How to Contribute

### Reporting Issues
- Check if the issue already exists in [Issues](../../issues)
- Open a new issue with a clear title and description
- Include your OS, compiler version, and steps to reproduce

### Suggesting Features
- Open an issue with the label `enhancement`
- Describe what the feature does and why it would be useful
- Bonus: sketch out how it might work in C++ (pseudocode or real code)

### Submitting Code Changes

1. **Fork** the repository
2. **Create a branch** from `main`:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Make your changes** — follow the existing code style (Allman brace style, clear comments)
4. **Test** your changes by compiling and running the program
5. **Commit** with a descriptive message:
   ```bash
   git commit -m "feat: add search employee by name feature"
   ```
6. **Push** to your fork and open a **Pull Request**

## 📐 Code Style Guidelines

- Use **Allman (BSD) brace style** (opening brace on new line)
- Comment each function and class clearly
- Keep classes focused — one class, one responsibility
- Use **meaningful variable names** (`employeeId`, not `x`)
- Prefer `const` where data should not be modified

## 💡 Ideas for Contributions

- [ ] Search employee by name
- [ ] File persistence (save/load employees from a `.txt` or `.csv`)
- [ ] Input validation (prevent duplicate IDs, negative salaries)
- [ ] Sorting employees by salary / name
- [ ] Display total payroll

## 📄 License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).
