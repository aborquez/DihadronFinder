DihadronFinder
=================

## Requirements

* **ROOT**

## Compilation

To compile just execute `make` in the current directory. The binary file (or execution file) will be located in directory `bin/`.

## Execution

At least one `pruned<target>_<rn>.root` file must be located in the same directory as the binary file. Usage is:

* To print usage and exit program:

  ```
  ./DihadronFinder_data -h
  ```

* To select the **file** to read: (the program will look for the file that satisfies the following filename scheme: `pruned<target>_<run number>.root`, ie, that were filtered by [**GetSimpleTuple**](http://github.com/utfsm-eg2-data-analysis))

  ```
  ./DihadronFinder_data -t<target> -r<run number>
  ``` 

  For example, if you have the file `prunedC_42011.root`, by executing the following, the program will read it.

  ```
  ./DihadronFinder_data -tC -r42011
  ```
  
## How to send jobs to the USM farm

Please, refer to `sh/README.md`
