
# Recursion Tree Visualizer

## Project Overview

The **Recursion Tree Visualizer** is a C++ program designed to illustrate how recursion works by visualizing recursive calls as a tree structure.showing how each recursive call branches out into further recursive calls. This visualization helps in understanding the flow of recursive functions and can be used for educational purposes to demonstrate the power and complexity of recursion.

The project allows users to input their recursive function definition, such as `febonacci(n)`, and visualize how it behaves for a given input (e.g., `febonacci(6)`). The recursion tree is drawn using ASCII art, making it easy to see how the function call splits and how the base case is reached.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Files in the Project](#files-in-the-project)
- [How It Works](#how-it-works)
- [Recursion Tree Structure](#recursion-tree-structure)
- [Example](#example)
- [How to Run the Program](#how-to-run-the-program)
- [Contribution Guidelines](#contribution-guidelines)
- [License](#license)

## Features

- **Recursive Function Visualization**: Automatically generates a recursion tree for a user-specified recursive function.
- **User Input**: Allows the user to input both the recursive function body and the initial function call (e.g., `febonacci(6);`).
- **ASCII Tree Output**: Displays the recursion tree in a visually structured ASCII art format, making it easy to trace the function's behavior.
- **Custom Functionality**: Users can modify the code to visualize other recursive functions by editing the input function and recursive logic.

## Files in the Project

- **replace.cpp**: This file contains the logic for receiving user input for the function body and function call. It inserts the user-defined code into the main program file (`code.cpp`), replacing the placeholders marked by comments (`//#code_here` and `//#function_call_here`).
- **recurtion.cpp**: This file defines the recursive logic for building the recursion tree, including creating tree nodes, performing level-order traversal, and printing the tree in a readable format.
- **code.cpp**: Contains the main function where the recursion is triggered. The user’s recursive function is inserted here, and the recursion tree is generated and displayed.

## How It Works

### 1. **User Input**:
   - The user is prompted to provide two inputs:
     1. The function call (e.g., `febonacci(6);`).
     2. The recursive function body, including the base condition (e.g., `if (n <= 1)`), and the stopping condition (`STOP`).
     
   The program takes these inputs and generates the required code in `code.cpp` by replacing placeholder comments with the user-defined function code and call.

### 2. **Building the Recursion Tree**:
   - The `recurtion.cpp` file handles the process of creating a tree structure that represents the recursive calls. Each recursive call is treated as a tree node.
   - The tree structure is then printed using level-order traversal to create a visual representation of how the recursion unfolds.

### 3. **Visualization**:
   - The recursion tree is displayed using ASCII art, with each function call being represented by a node. The recursive calls are shown as branches connecting parent nodes to child nodes. When the recursion reaches the base case (`n <= 1`), the branches stop.

## Recursion Tree Structure

The program visualizes recursive calls as a binary tree. Each node represents a function call, and the two child nodes represent the recursive calls that are made within the function. Here’s an example recursion tree for `febonacci(6)`:

```
                                   6
                                /     \
                             5           4
                           /   \       /    \
                         4       3    3       2
                       /   \     /  \   /  \    /  \
                     3      2  2    1  2    1  1    0
                    /  \   /  \ /   \        /  \
                   2    1 1    0 1   0      1    0
                  /  \
                 1    0

```

- **Root**: The first function call (`febonacci(6)`).
- **Branches**: Each recursive call splits into two: `febonacci(n-1)` and `febonacci(n-2)`.
- **Base Case**: The recursion stops when `n <= 1`, represented as the leaf nodes of the tree.

## Example

Here is a sample interaction with the program:

### Input:
```
Enter the function call: febonacci(6);
Enter the complete function body with a //base_condition as a comment right above a base condition and last line as "STOP" to stop the input:
int febonacci(int n) {
    if (n <= 1){
        //base_condition
        return n;
    }
    return febonacci(n - 1) + febonacci(n - 2);
}
STOP
```

## How to Run the Program

### Prerequisites:

- You must have a C++ compiler installed (e.g., `g++` for Linux/Mac or `MinGW` for Windows).

### Steps to Run:

1. **Clone the Repository**:
   - Clone the repository to your local machine using Git:
   ```bash
   git clone https://github.com/yourusername/recursion-tree-visualizer.git
   ```
   
2. **Compile the Code**:
   Open a terminal or command prompt and navigate to the project directory. Run the following command to compile the program:

   ```bash
   g++ replace.cpp -o replace
   ```

3. **Run the Program**:
   After compiling, run the program with:

   ```bash
   ./replace
   ```

4. **Provide Input**:
   - Enter the function call (e.g., `febonacci(6);`).
   - Enter the function body (e.g., the Fibonacci function code, including the base condition and stopping condition (`STOP`)).

5. **View the Output**:
   The program will print the recursion tree for the input function call.

### Example:

```
Enter the function call: febonacci(6);
Enter the complete function body with a //base_condition as a comment right above a base condition and last line as "STOP" to stop the input:
int febonacci(int n) {
    if (n <= 1){
        //base_condition
        return n;
    }
    return febonacci(n - 1) + febonacci(n - 2);
}
STOP
```

### Output:
```
                                   6
                                /     \
                             5           4
                           /   \       /    \
                         4       3    3       2
                       /   \     /  \   /  \    /  \
                     3      2  2    1  2    1  1    0
                    /  \   /  \ /   \        /  \
                   2    1 1    0 1   0      1    0
                  /  \
                 1    0

```

## Contribution Guidelines

Feel free to fork this repository and submit pull requests for bug fixes, new features, or improvements to the program. If you encounter any issues or have suggestions, open an issue on GitHub.

### How to Contribute:

1. Fork the repository.
2. Create a new branch for your changes (`git checkout -b feature-name`).
3. Make the necessary changes or improvements.
4. Commit your changes (`git commit -m "Your message"`).
5. Push your changes to your fork (`git push origin feature-name`).
6. Open a pull request.


