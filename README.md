# pam_sqlite3

Hi there.

thanks to see my small and fun (maybe dirty) project.

`pam_sqlite3` is an open source pam module for authenticate services using sqlite3.

### compiled and test on

- 5.10.34-1-MANJARO

# dependencies

- cmake ( >= v3.2)
- libsqlite3
- PAM headers

## dependency installation

### manjaro

already supported manjaro.

### centos8

centos support coming soon

```
# dnf install cmake libarchive gcc gcc-c++ libsqlite3-dev libsqlite3x-devel pam-devel
```

### FreeBSD

FreeBSD support comming soon

# Installation

```
$ git clone https://github.com/alirezaarzehgar/pam_sqlite3.git
```

when you cloned this repository on your computer, you can change config.h.in.

this file contain `DB_PATH` macro for reading data.

```
#define DB_PATH "/path/mydbpath.db"
```

it's better this path choses from standard locations like `/var/db/service`, `/root/.config/pam_sqlite3`, `/etc/service` and etc.
this path by default located on `/var/db/sshd/shadow.db`.

please make sure your custom location subdir is already exists.

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
# make install
```

## Database Initialization

I have not yet implemented sqlite3 front-ent for user CRUD.
But I hope to add this part

however you should initialize your database manually.

first of all you should create your database directory.

this is for me :

```
# mkdir -p /var/db/sshd
```

then you should initialize you db.

```
# sqlite3 /var/db/sshd/shadow.db
sqlite> CREATE TABLE users (id INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT, username STRING, password STRING);
```

then you can enter a user.

```
sqlite> INSERT INTO users (username, password) VALUES('ali','1a1dc91c907325c69271ddf0c944bc72');
```

in this case my password is `password`.

note that your password should be md5.

you can create md5 password using this command

```
$ printf password | md5sum
```

# Usage

now you are already installed libpam_sqlite3.so.

you can add this pam module to every pam config that you want.

for example i would change sshd pam config.

you just write this lines top of `/etc/pam.d/sshd`

```
auth           sufficient      libpam_sqlite3.so
account        sufficient      libpam_sqlite3.so
```

this lines apply `libpam_sqlite3.so` rules to sshd service.

then you can ssh to you configured server with defined users on database.

```
$ ssh ali@localhost
```
