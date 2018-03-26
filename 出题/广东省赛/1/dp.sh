while true; do  
./data>a.in 
./did<a.in>did.out   
./a <a.in>a.out 
if diff a.out did.out; then 
printf AC 
else  
echo WA  
exit 0  
fi 
done 
