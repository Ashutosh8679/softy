# Proteus 8 Simulation Guide

This folder contains the Proteus 8 simulation files for this project, along with all required external libraries.

---

## 📂 Folder Structure

- `project_files/` → Main Proteus design files (`.pdsprj`)
- `libraries/` → External libraries required for the simulation

---

## ⚙️ Requirements

- Proteus 8 Professional (recommended version 8.13 or later)

---

## 📥 Installing Required Libraries

1. Open the `libraries/` folder.
2. Copy all `.LIB` and `.IDX` files.
3. Paste them into your Proteus library directory: *(In some systems, the path may be inside `ProgramData` instead.)*
4. Restart Proteus after copying the files.

---

## ▶️ Running the Simulation

1. Open the `.pdsprj` file from the `project_files/` folder.
2. Click the **Run (▶️)** button.
3. Interact with the circuit as required.

---

## 📚 External Libraries Used

### 1. FSR Sensor (FSR-406) Library  
- Source: https://electronicstree.com/arduino-fsr-sensor-proteus-library/  
- Description:  
Provides a force-sensitive resistor model that simulates resistance changes based on applied pressure. :contentReference[oaicite:0]{index=0}  

---

### 2. Arduino Library for Proteus  
- Source: https://github.com/cyberponk/Arduino-Library-for-Proteus/tree/master  
- Description:  
Includes Arduino boards (e.g., Nano, Micro) with internal circuits, packages, and simulation models for use in Proteus. :contentReference[oaicite:1]{index=1}  

---

## ⚠️ Notes

- Ensure all libraries are installed **before opening the project**, otherwise components may appear missing.
- If the simulation does not run, verify that:
- The correct `.HEX` file is loaded (if applicable)
- All dependencies are properly installed

---

## 📌 Attribution

All external libraries belong to their respective creators.  
This repository only includes them for educational and simulation purposes.