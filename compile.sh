make
ls -latrR > empty_dir/file.txt
./ft_ls -latrR > empty_dir/ft_file.txt
diff empty_dir/file.txt empty_dir/ft_file.txt
make clean