# pam_sqlites

Hi dear.

thanks to see my smal and fun (maybe dirty) project.

`pam_sqlite3` is a open source pam module for authenticate services using sqlite3.

# dependencies

- cmake ( >= v3.2)
- libsqlite3
- PAM headers

# Installation

`$ git clone`

when you cloned this repository on your computer, you can change config.h.in.

this file contain `DB_PATH` micro for reading data.

```
#define DB_PATH "/path/mydbpath.db"
```

it's better this path choses from standard locations like `/var/db/service`, `/root/.config/pam_sqlite3`, `/etc/service` and etc.
this path by default located on `/var/db/sshd/shadoe.db`.

please make sure your custom location subdir is already exists.

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
# make install
```

# Usage

now you are already installed libpam_sqlite3.so.

you can add this pam module to every pam config that you want.

for example i would change sshd pam config.

you just write this lines top of `/etc/pam.d/sshd`

```
auth    sufficient      libpam_sqlite3.so
account sufficient      libpam_sqlite3.so

```
