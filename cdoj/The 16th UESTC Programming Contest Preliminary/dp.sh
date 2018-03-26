while true; do  
./data>k.in 
./did<k.in>did.out   
./k <k.in>k.out 
if diff k.out did.out; then 
printf AC 
else  
echo WA  
exit 0  
fi 
done 
