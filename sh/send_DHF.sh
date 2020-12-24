#!/bin/bash

##############################################################
# ./send_DHF.sh <target>                                     #
#     <target> = (C, Fe, Pb)                                 #
#                                                            #
# EG: ./send_DHF.sh C                                        #
#     ./send_DHF.sh Fe                                       #
#     ./send_DHF.sh Pb                                       #
##############################################################

#####
# Input
###

TARNAME="$@"

#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
DHFDIR=${HOME}/DihadronFinder
GSTDIR=/eos/user/b/borquez/out/GetSimpleTuple_data/${TARNAME}           # input dir
OUTDIR=/eos/user/${USER:0:1}/${USER}/out/DihadronFinder_data/${TARNAME} # output dir
TMPDIR=/eos/user/${USER:0:1}/${USER}/tmp/DihadronFinder_data/${TARNAME} # temp dir to store logs and job scripts
mkdir -p ${OUTDIR} ${TMPDIR} # just in case

for file in ${GSTDIR}/*; do
    # update rn value
    RN=${file##*_}
    RN=${RN%.root}
    
    # setting jobname
    jobname="DHF_${TARNAME}_${RN}"
    jobfile="${TMPDIR}/${jobname}.sh"

    echo ${jobname}

    echo "#!/bin/bash"                                                 > ${jobfile}
    echo "#SBATCH -J ${jobname}"                                      >> ${jobfile}
    echo "#SBATCH -o ${TMPDIR}/${jobname}.out"                        >> ${jobfile}
    echo "#SBATCH -e ${TMPDIR}/${jobname}.err"                        >> ${jobfile}
    echo "#SBATCH --time=1:00:00"                                     >> ${jobfile} # 1hrs or 15min for test
    echo "#SBATCH --mem=1GB"                                          >> ${jobfile}
    echo ""                                                           >> ${jobfile}
    echo "source ${HOME}/.bashrc"                                     >> ${jobfile}
    echo "cd ${DHFDIR}/bin"                                           >> ${jobfile}
    echo "ln -s ${file} ${file##*/}"                                  >> ${jobfile} # create symbolic link to input file with DHF naming scheme
    echo "./DihadronFinder_data -t${TARNAME} -r${RN}"                 >> ${jobfile} # execute program
    echo "mv -v dihadron${TARNAME}_${RN}.root ${OUTDIR}/"             >> ${jobfile} # move outfile to outdir
    echo "rm -v pruned${TARNAME}_${RN}.root"                          >> ${jobfile} # removing symbolic link

    echo "Submitting job: ${jobfile}"
    sbatch ${jobfile} # submit job!
done
