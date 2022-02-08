# GET_Next_Line
Hive Helsinki / Get_Next_Line 

## :arrow_right: Project's goal:

This project is a function that reads one line at the time from a given text file.
The line should be ending by ```'\n'``` newline character so it can move forward for
the next line.

## 	:heavy_plus_sign: Installation:

1-  ```git clone git@github.com:omaralsakka/GET_Next_Line.git```

2-  ```cd libft```

3-  ```make```

## :open_book: User guide:

1-  create a file descriptor by opening a text file, for example:

``` fd = open("file.txt", O_RDONLY);```

2-  create a string variable:

```char *str;```

3-  send the string address and file descriptor into the function:

```get_next_line(fd, &str);```

4-  print the string content:

```ft_putstr(str);```

## :exclamation: Note:

This function ```returns 0``` when no lines left to read, hence it can be used as a ```while loop``` condition
