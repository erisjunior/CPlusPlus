# Programming Language I

This is a repository containing all the subjects I have seen in a college class, all C++ based. Using the main language concepts, we created a simple project exploring some functionalities. The project is described below:

Note:
All the folders named `class_x` are usually examples of a new topic, more specified in the commit message. After the seventh class, we were focused on the diary project, so everything is in the `diary` folder, but still with the commit messages about all classes.

## Diary

The project is a simple diary, where you can take notes and they are organized by date and time. We started it simply, only writing in a file, but a little messy, because we do everything in a `main.cpp`.
We started to study TADs and organize the code in some better ways.

The main functionalities are:

Add: `./diary add <message>` to add a new note, and it will be grouped with other messages of the same day, and carry its own time.
Add: `./diary add` Same as the above one, but now the user will type the message in the program.

List: `./diary list` to list (obviously) all the note until this moment.

Interactive Mode: `./diary interactive` Is a different way to use the program, with more texts and details, navigating with number through the actions.
