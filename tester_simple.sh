if [ $# -ne 1 ]
then
   echo "Supply the Cache Size"
   exit
fi

for blockFactor in 1 2 4 5 10 20 25 50 100
    do 
      echo 'Blockfactor used' ${blockFactor}
        ./blocking ${blockFactor} | ./cache -s$1k 
done
