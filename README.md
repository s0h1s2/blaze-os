# Blaze Operating System 
##### Currently under development.
Blaze is operating system written from scratch for eductional pruposes.

# Toolchain Build
Building toolchain only supported on **linux** operating systems currently to build the toolchain type the following commands on your terminal.
```
	cd Cross-Compiler/
	sh build.sh 

```
By default the binary files will be generated at ```$HOME/opt/cross``` and you need to export it on global path.

If you are on another operating system you can follow on [here](https://wiki.osdev.org/GCC_Cross-Compiler).

# Build And Test
After you build the toolchain you can test the operating system by typing the following commands at your terminal.
```	
	make
```
It will generate a binary file by name of **os.bin** on **Build** directory.
To test the operating system you can type the following command.
```
	make run
```

# Contributions
Any contribution will be welcome.
