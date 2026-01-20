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

cp filename Documents/

The file will be moved to the location.

ps - Processes
Lists active processes with process ids and time stamps. Specific processes can be selected based on factors like pid.
However, htop or top is better for active process monitoring.

ps

 PID TTY          TIME CMD
  48372 pts/0    00:00:00 bash
  59093 pts/0    00:00:00 ps
The above example will be displayed.

ls - List
Lists contents of the specified directory (or current one with no directory passed as a parameter). There are many option
flags, but a useful set of options are -lai to list all files, including hidden ones, an index number, and with long format.

ls

The files and directories in the current directory will be listed:
tuser501.txt  tuser502.txt  tuser503.txt  tuser504.txt  tuser505.txt  tuser506.txt  tuser507.txt  tuser508.txt  tuser509.txt  tuser510.txt

mv - Move
Moves a a file (first parameter) to a location (second parameter). It can also be used to rename a file by moving the file
in the current directory. Similar options available as cp, to include making backups.

mv test.txt renamed.txt

The file will be moved

rm - Remove
Removes files or directories. The "r" flag must be specified for directories to recursively remove them. This is also
one of the most notorious commands in that it can be used to recursively remove all files starting from and including
the root itself with several options specified, effectively allowing one to ruin the Linux install on that disk with a
single command.

sudo rm -rf --no-preserve-root /

This command will wipe the Linux install.

mkdir - Make Directory
Makes a new directory with the specified name/filepath. Most useful option is "p" for creating parent directories if
they do not exist along with the new directory.

mkdir test

A directory named test will be made.

rmdir - Remove Directory
Similar to mkdir, but removes empty directories.

rmdir test

Test directory will be removed.

pwd - Print Working Directory
Prints the current directory. A useful command for scripting if the directory is not known.

pwd

Prints the working directory the user is currently in.

stat - Status
Displays file status which includes last access, modify, change, and creation time along with access privileges.

stat tuser506.txt

Results in:
  File: tuser506.txt
  Size: 7         	Blocks: 8          IO Block: 4096   regular file
Device: 8,18	Inode: 12607367    Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/ ihseymo)   Gid: ( 1000/ ihseymo)
Access: 2026-01-19 13:56:15.901940876 -0800
Modify: 2026-01-19 13:56:15.901940876 -0800
Change: 2026-01-19 13:56:15.901940876 -0800
 Birth: 2026-01-19 13:56:15.901940876 -0800

tar - Archiving Utility
Used to bundle multiple files or a directory into an "archive" or compressed folder.

tar -czvf archive.tar testdirectory

Creates a compressed tar of testdirectory.

apt - Package Manager (used by Ubuntu)
Utility that allows you to install, remove, and update packages. Very commonly used.

apt install firefox

Installs Firefox package.

echo - Display Text
Outputs a string (passed as parameter) to the standard out.

echo test

Outputs "test"

cat - Concatenate
Prints contents of a file to the standard out.

cat filename

Prints contents of filename.

more - Display Contents
Displays the contents of a file to the standard out (similar to cat but more intended for reading
an entire file).

more filename

Prints contents of filename.

less - Display Contents
Displays the contents of a file like "more" but has more advanced features.

less filename

Prints contents in what is basically a read version of Vim.

date - Date
Prints the system date and time or can be used to set the time. There are many options for changing
formatting of the date-time-group.

date

Prints system time.

time - Tracks Program Time
When used with running a program, it returns a summary of system resources used by the program after
it terminates.

time ls

Prints how long it took to run ls command.

kill - Terminate Process
Stops the specified process identified by the process id passed as a parameter.

kill "pid"

Kills the process with the entered pid.

history - History of Commands
Prints a list to the standard out of commands used with an index.

history

Lists command history.

chmod - Change File Mode
This command can change the file permissions (read, write, execute and by who). One way of passing this info
as a parameter can be done with three octets where the first is the "owner" permissions, the second is the "group,"
and the third are "others" permissions. 7 (or 111) grants read, write and execute permission to that group, for example.

chmod 777 filename

Changes file to have read, write, and execute permission for all groups.

chown - Change Owner
Similar to chmod but used to change the owner of a file.

chown "user" filename

Changes the file to the specified user.

