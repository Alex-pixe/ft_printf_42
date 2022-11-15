# ft_printf
project for ecole 42

You need to recode printf function with "cspdiuxX%" type fields!  
if you don't understand what it means or what type fields mean  
you can read about it [here](https://en.wikipedia.org/wiki/Printf_format_string)
  
Bonus part: it should work with "0-+# " (space is also flag) flags and with precision  
and width of a standard printf!
  
* You can see the full assignment here [subject](https://github.com/cbridget42/ft_printf_42/blob/main/subject/en.subject.pdf)
* Coding style: [norminette](https://github.com/cbridget42/ft_printf_42/blob/main/subject/en.norm.pdf)
  
### Usage:
* first you need to download the repository and compile the code! To do this, run:
	```bash
	git clone git@github.com:cbridget42/ft_printf_42.git
	cd ft_printf_42
	make
	make bonus //compile with bonus
	```
* then you will have a libftprintf.a file.
	+ to use it you need to add headers/ft_printf.h header to your project.
	+ compile your project with -Lft_printf_42 -lftprintf flags
* also you can:
	```bash
	make clean //remove objects files
	make fclean //remove objects files and libftprintf.a
	```
* a simple call could be like this:
	```c
	ft_printf("Hello, my name is %s. I'm %d years old.\n", "Jessica", 18);
	```
  
### Tests:
![image](https://github.com/cbridget42/ft_printf_42/blob/main/images/Screen%20Shot%202022-11-15%20at%203.06.36%20PM.png)
  
### final score:
![image](https://github.com/cbridget42/ft_printf_42/blob/main/images/Screenshot%20from%202022-11-13%2020-39-39.png)
  
