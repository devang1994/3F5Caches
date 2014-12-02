

for cacheSize in 1 2 4 8 16 32 64
  do
    for blockFactor in 1 2 4 5 10 20 25 50 100
      do 
        echo 'Blockfactor used' ${blockFactor}
        ./blocking ${blockFactor} | ./cache -s${cacheSize}k 
    done
done
