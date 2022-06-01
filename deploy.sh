cd build
make -j$(nproc)
scp -o LogLevel=Error picontroller importly@192.168.1.105:
echo ...................... deploy complete ......................

ssh importly@192.168.1.105 sudo ./picontroller