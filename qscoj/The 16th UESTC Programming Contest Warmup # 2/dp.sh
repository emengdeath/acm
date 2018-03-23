while true; do  
./data>j.in 
./did<j.in>did.out   
./j <j.in>j.out 
if diff j.out did.out; then 
printf AC 
else  
echo WA  
exit 0  
fi 
done 
