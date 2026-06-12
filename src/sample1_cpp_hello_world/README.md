# Hello World - ROS2 Lyrical (C++)

A simple ROS2 C++ node that prints "Hello World!" to the console every second.

---

## Project Structure

```
learn_ros2/
└── src/                          ← colcon workspace source folder
    └── sample1_cpp_hello_world/  ← this ROS2 package
        ├── .vscode/
        │   ├── c_cpp_properties.json   # IntelliSense config
        │   ├── tasks.json              # Build & run tasks
        │   ├── launch.json             # Debug config
        │   └── settings.json          # VS Code settings
        ├── src/
        │   └── hello_world_node.cpp   # Node source code
        ├── CMakeLists.txt
        └── package.xml
```

> **Important:** colcon expects your package to be inside a `src/` folder at the workspace root.  
> Move this package so the layout is:  
> `~/ros2_ws/src/sample1_cpp_hello_world/`

---

## Prerequisites

1. **ROS2 Lyrical** installed on Ubuntu:
   ```bash
   # Verify installation
   source /opt/ros/lyrical/setup.bash
   ros2 --version
   ```

2. **colcon** build tool:
   ```bash
   sudo apt install python3-colcon-common-extensions
   ```

3. **VS Code Extensions** (install from the Extensions panel):
   - `ms-vscode.cpptools` — C/C++ IntelliSense & debugging
   - `ms-vscode.cmake-tools` — CMake support (optional)

---

## Setup: Workspace Layout

```bash
mkdir -p ~/ros2_ws/src
cp -r /path/to/sample1_cpp_hello_world ~/ros2_ws/src/
cd ~/ros2_ws
```

---

## Building

### Option A — VS Code Task (recommended)

1. Open the `sample1_cpp_hello_world` folder in VS Code.
2. Press **Ctrl+Shift+B** → select **colcon: build (this package)**.

### Option B — Terminal

```bash
cd ~/ros2_ws
source /opt/ros/lyrical/setup.bash
colcon build --packages-select hello_world --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

---

## Running

```bash
# Source both ROS2 and the local workspace
source /opt/ros/lyrical/setup.bash
source ~/ros2_ws/install/setup.bash

ros2 run hello_world hello_world_node
```

Expected output:
```
[INFO] [hello_world_node]: Hello, ROS2 Lyrical! Node has started.
[INFO] [hello_world_node]: Hello World! - ROS2 Lyrical
[INFO] [hello_world_node]: Hello World! - ROS2 Lyrical
...
```

---

## Debugging in VS Code

1. Build the package first (**Ctrl+Shift+B**).
2. Open `src/hello_world_node.cpp` and set breakpoints.
3. Press **F5** → select **Debug hello_world_node**.

---

## Cleaning the Build

Run the **colcon: clean** task in VS Code, or:

```bash
cd ~/ros2_ws
rm -rf build/ install/ log/
```

