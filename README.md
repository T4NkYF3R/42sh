# 42sh – Unix Shell Implementation

> 🛠️ Epitech Tech1 Final Project – Shell Implementation inspired by TCSH

---

## 📌 Description

**42sh** is a fully functional Unix shell implemented in C, developed as a group project during the first year at Epitech.  
It mimics the behavior of the `tcsh` shell, and includes many essential and advanced features such as globbing, job control, variable handling, and command history.

The main goals of the project were **stability**, **feature completeness**, and **code maintainability**.

---

## 🚀 Features

- 🔁 Command execution with support for:
  - Inhibitors: `' '`
  - Globbing: `*`, `?`, `[ ]`
  - Job control: `&`, `fg`, `bg`
  - Backticks: `` ` ``
  - Parentheses: `( )`
- 💬 Local and environment variables
- 🧠 Special variables (e.g., `term`, `precmd`, `cwd`, `ignoreof`, etc.)
- 📜 Command history with `!`
- 🧾 Alias support (e.g., `alias ls "ls --color"`)
- 📝 Line edition:
  - Multiline input
  - Dynamic key rebinding
  - Auto-completion
- ✅ Error handling consistent with `tcsh` return codes

---

## 🛠️ Compilation

Use the provided `Makefile` with the following rules:
```bash
# Build the project
make

# Remove temporary files
make clean

# Remove all build artifacts including the binary
make fclean

# Clean and rebuild everything
make re
```

---

## 📁 Project Structure

```bash
.
├── alias.c
├── alias_display.c
├── alias_set.c
├── array_modif.c
├── autocomplete2.c
├── autocomplete3.c
├── autocomplete4.c
├── autocomplete.c
├── backticks.c
├── binary.c
├── cd_cmd.c
├── crocus.c
├── env_cmd1.c
├── env_cmd2.c
├── env_var.c
├── error_messages.c
├── find.c
├── fleches.c
├── fork_exec_prompt.c
├── free_tabs.c
├── get_path.c
├── globings.c
├── history.c
├── history_ex.c
├── left_red.c
├── libc2.c
├── libc.c
├── local_environement.txt
├── main.c
├── main_loops.c
├── Makefile
├── miss_quote.c
├── my_env.c
├── my.h
├── nums2.c
├── nums3.c
├── nums.c
├── parentheses.c
├── parse_cmd.c
├── parse_flags.c
├── pipe_red2.c
├── pipe_red.c
├── README.md
├── repeat.c
├── replace_alias.c
├── right_red.c
├── set2.c
├── set.c
├── set_var.c
├── spaces_to_array.c
├── str_to_backticks.c
├── strtow.c
├── str_to_word_array.c
├── stwa.c
└── unalias.c
```

---

## 👥 Team

Project developed during 8 weeks by a team of 5 students from Epitech.

---

## 📚 Requirements

- 🧠 Language: C (compliant with C99 or later)
- 📦 Libraries: Standard libc and ncurses only

---

## 💡 Tips for Reviewers

- All error messages are printed to stderr
- The shell exits with the same codes as tcsh in case of errors

## 📜 License

This project is part of Epitech’s academic curriculum and is not licensed for commercial use.
