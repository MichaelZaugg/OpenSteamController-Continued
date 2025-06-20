# 🔧 BLE Firmware Reverse Engineering Project

This is an active subproject focused on **decompiling and understanding the Bluetooth Low Energy (BLE) firmware** for a specific device. The ultimate goal is to allow developers and hobbyists to **customize the firmware** for their own projects—whether that's for experimentation, bug fixing, or extending device functionality.

---

## Overview

Reverse engineering this firmware involves disassembling binary code, analyzing machine instructions, and reconstructing a high-level understanding of how the firmware operates. This project uses **Ghidra**, a powerful open-source reverse engineering tool developed by the NSA.

---

## Tools and Resources

### 🔍 Ghidra

**Ghidra** is the primary tool used in this project. It can:
- Decompile machine code into assembly.
- Decompile assembly into human-readable, C-like pseudocode.
- Help analyze unknown binaries, firmware images, and microcontroller firmware.

#### 🔗 Official Repo:
- [NSA's Ghidra on GitHub](https://github.com/NationalSecurityAgency/ghidra)

---

## 📥 How to Install Ghidra

Choose your operating system below:

### Windows & macOS
Download the official ZIP from the [Ghidra website](https://ghidra-sre.org)

1. Unzip the archive.
2. Run the `ghidraRun` script in the extracted directory.

---

### Linux

#### Arch Linux / Manjaro
```bash
sudo pacman -S ghidra
# or if using an AUR helper:
yay -S ghidra
```

#### Ubuntu / Debian
```bash
sudo apt update
sudo apt install openjdk-17-jdk  # Ghidra requires Java 17+

# Download the latest Ghidra zip
wget https://ghidra-sre.org/ghidra_11.3.2_PUBLIC_20250415.zip

# Unzip and run
unzip ghidra_11.3.2_PUBLIC_20250415.zip
cd ghidra_11.3.2_PUBLIC
./ghidraRun
```

#### Flatpak
```bash
flatpak remote-add --user flathub-beta https://flathub.org/beta-repo/flathub-beta.flatpakrepo
flatpak install --user flathub-beta org.ghidra_sre.Ghidra

# Run Ghidra
flatpak run org.ghidra_sre.Ghidra
```

# 📦 Project Components
## 📁 [lpc_chip_11uxx_lib](../lpc_chip_11uxx_lib)

This folder contains:

- Vendor-provided or extracted hardware abstraction libraries.
- Useful for referencing register definitions, macros, and I/O configurations for the LPC11UXX microcontroller family.

## 🚧 Project Status

This project is currently in early development. Contributions and collaboration are welcome. The first milestone is to achieve a full decompilation and annotation of the firmware's structure and functions.
