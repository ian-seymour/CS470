Script Description:
A bash script that creates a main directory with the current date-time as the name. Within this directory, the script
creates ten sub-directories (named "file101" to "file110"). Within each sub-directory, it creates ten text files that
contain a random programming language name randomly picked from an array of language options. Each file is named "tuser501"
to "tuser510". The script also generates a log file (if it does not already exist), and logs actions with date/time
in the log file.

Bash Commands:
cp - Copy
Copies a file or directory taking a source file/directory as the first parameter and destination as the second. It has
optional flags that can be used to backup the files being copied, link files rather than copying, and copy directories
recursively among many more.

ps - Processes
Lists active processes with process ids and time stamps. Specific processes can be selected based on factors like pid.
However, htop or top is better for active process monitoring.

ls - List
Lists contents of the specified directory (or current one with no directory passed as a parameter). There are many option
flags, but a useful set of options are -lai to list all files, including hidden ones, an index number, and with long format.

mv - Move
Moves a a file (first parameter) to a location (second parameter). It can also be used to rename a file by moving the file
in the current directory. Similar options available as cp, to include making backups.

rm - Remove
Removes files or directories. The "r" flag must be specified for directories to recursively remove them. This is also
one of the most notorious commands in that it can be used to recursively remove all files starting from and including
the root itself with several options specified, effectively allowing one to ruin the Linux install on that disk with a
single command.

mkdir - Make Directory
Makes a new directory with the specified name/filepath. Most useful option is "p" for creating parent directories if
they do not exist along with the new directory.

rmdir - Remove Directory
Similar to mkdir, but removes empty directories.

pwd - Print Working Directory
Prints the current directory. A useful command for scripting if the directory is not known.

stat - Status
Displays file status which includes last access, modify, change, and creation time along with access privileges.

tar - Archiving Utility
Used to bundle multiple files or a directory into an "archive" or compressed folder.

apt - Package Manager (used by Ubuntu)
Utility that allows you to install, remove, and update packages. Very commonly used.

echo - Display Text
Outputs a string (passed as parameter) to the standard out.

cat - Concatenate
Prints contents of a file to the standard out.

more - Display Contents
Displays the contents of a file to the standard out (similar to cat but more intended for reading
an entire file).

less - Display Contents
Displays the contents of a file like "more" but has more advanced features.

date - Date
Prints the system date and time or can be used to set the time. There are many options for changing
formatting of the date-time-group.

time - Tracks Program Time
When used with running a program, it returns a summary of system resources used by the program after
it terminates.

kill - Terminate Process
Stops the specified process identified by the process id passed as a parameter.

history - History of Commands
Prints a list to the standard out of commands used with an index.

chmod - Change File Mode
This command can change the file permissions (read, write, execute and by who). One way of passing this info
as a parameter can be done with three octets where the first is the "owner" permissions, the second is the "group,"
and the third are "others" permissions. 7 (or 111) grants read, write and execute permission to that group, for example.

chown - Change Owner
Similar to chmod but used to change the owner of a file.

