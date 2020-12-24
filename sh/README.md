# DihadronFinder/sh

Here are located all the necessary bash scripts for sending jobs and executing bulk operations.
These scripts are prepared to run **exclusively** at **USM cluster**.

## send_DHF.sh

This **Bash** script creates a job file that is submitted into USM farm, that is in charge of executing **DihadronFinder_data**
for all the root data files in [**GetSimpleTuple**](http://github.com/utfsm-eg2-data-analysis/GetSimpleTuple) format.

Usage is:

```
./send_DHF.sh <target>
```

where:

* `<target> = (C, Fe, Pb)`

Feel free to edit the directories `DHFDIR`, `OUTDIR`, `TMPDIR` at convenience.

If you run this script for each target, you would be sending a total of 549 jobs, one per each **Run Number**.
