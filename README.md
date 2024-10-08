# Fuzzy Testing Core

**Fuzzy Testing Core** is a project that provides a Dockerized environment for running fuzzing experiments with [AFL++](https://github.com/AFLplusplus/AFLplusplus) and debugging with GDB. This repository automates the setup process, providing a simple interface using `make` commands to build, run, and connect to a containerized environment.

> **Note**: This project is under active development, and there is no guarantee of complete functionality or stability at this stage.

## Prerequisites

Before using this project, ensure that you have the following installed:

- **Docker**: To build and run the container image.
- **Make**: Required to use the simplified commands for building, running, and managing the container.
- **Virtual Hard Drive Setup**: The container uses a virtual hard drive (VHD) to share files between the host and container.

## Getting Started

### Step 1: Clone the Repository

First, clone the repository to your local machine (Windows):

```bash
git clone https://github.com/devcoons/fuzzy-testing.git
cd fuzzy-testing
```

### Step 2: Create a Folder and Set Up the Virtual Hard Drive

You need to create a folder on your local machine that will be shared with the container through a virtual hard drive.

1. Create a folder on your PC to store files to be shared with the container. This folder can be located anywhere on your machine.
2. Execute the `install-startup-vhd.bat` script (as admin). This script will create a virtual hard drive that maps to the folder you just created.
   
   ```bash
   .\install-startup-vhd.bat
   ```

   You will be prompted to provide the folder path that you created in step 1. Once done, the script will create a virtual hard drive under the letter `M:`. This drive will link to the folder you specified.

   > Note: Please restart your PC once.


### Step 3: Build the Docker Container Image

To build the Docker image with AFL++ and GDB pre-installed, run the following command:

```bash
make build
```

This will create a container image using the Dockerfile and install the necessary tools.

### Step 4: Run the Container

After the image is built, you can start the container. The `M:` drive will automatically be linked to `/mnt/m` inside the container for file sharing between the host and container.

To run the container, use the following command:

```bash
make run
```

### Step 5: Connect to the Running Container

To access the container’s terminal and begin your fuzzing experiments, you can connect to the running container's console using:

```bash
make connect
```

This command simplifies the process of connecting to the container, avoiding the need to manually execute long Docker commands.

## Examples

To test the examples, follow these steps:

1. Copy the example folder to the `M:` virtual hard drive.
2. Connect to the container and navigate to the `/mnt/m` directory.
3. Run the following commands:

   - `make build`: This will generate the binary.
   - `make run`: This will start the fuzz testing. 

## Development Status

This repository is currently under active development. Features and functionality may change over time, and there are no guarantees that everything will work perfectly at this stage.

## Troubleshooting

If you encounter any issues while setting up or running the container, please check the following:

- Ensure Docker is running on your machine.
- Ensure the `make` command is installed and accessible.
- Ensure that the virtual hard drive (`M:`) was created successfully by running the `install-startup-vhd.bat` script.

For additional help, feel free to create an issue on the repository.
