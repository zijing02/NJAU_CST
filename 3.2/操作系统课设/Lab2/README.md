## Getting Started

Welcome to the VS Code Java world. Here is a guideline to help you get started to write Java code in Visual Studio Code.

## Folder Structure

The workspace contains two folders by default, where:

- `src`: the folder to maintain sources
- `lib`: the folder to maintain dependencies

Meanwhile, the compiled output files will be generated in the `bin` folder by default.

> If you want to customize the folder structure, open `.vscode/settings.json` and update the related settings there.

## Problem
There is a problem that the code will cause a death lock while running, but due to my finite ability, I haven't find why.
The most possible question it that the *await* function will unlock the lock an let another thread to run. As soon as the other thread run through the *signal()* code, the project will run into a death lock as there is no *signal()* code to wake the *await*.
To solve the problem, the easiest way is change the *unlock* in *ProcessSchedulingHandlerThread* to *lock* or directly *delete* it.
Another way is *add lock* again while finish *await*.
However, I think neither of the two way is a good solution. If you have some good ideas, leave a comment.
## Dependency Management

The `JAVA PROJECTS` view allows you to manage your dependencies. More details can be found [here](https://github.com/microsoft/vscode-java-dependency#manage-dependencies).
