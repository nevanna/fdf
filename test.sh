clear
echo "\033[35;5;5mvalidation wrong map \033[0m"
echo "-------------------------------------------------------------"
echo "\033[32mmap 0:empty map \033[0m"
./fdf test/test_map_error/map0
echo " "
echo "\033[32mmap 1:random\033[0m"
./fdf test/test_map_error/map1
echo " "
echo "\033[32mmap 2:wrong symbols\033[0m"
./fdf test/test_map_error/map2
echo " "
echo "\033[32mmap 3:wrong len\033[0m"
./fdf test/test_map_error/map3
echo " "
echo "\033[32mmap 4:only n\033[0m"
./fdf test/test_map_error/map4
echo " "
echo "\033[32mmap 5:wrong color\033[0m"
./fdf test/test_map_error/map5
echo " "
echo "\033[32mmap 6:wrong color\033[0m"
./fdf test/test_map_error/map6
echo " "
echo "\033[32mmap 7:wrong nb\033[0m"
./fdf test/test_map_error/map7
echo " "
echo "\033[32mmap 8:wrong symbols\033[0m"
./fdf test/test_map_error/map8
echo " "
echo "\033[32mmap 9:wrong last lines\033[0m"
./fdf test/test_map_error/map9
echo " "
echo "\033[32mmap 10:wrong!!\033[0m"
./fdf test/test_map_error/map10
echo " "
echo "\033[32mmap 11:no file\033[0m"
./fdf test/test_map_error/map11
echo " "
echo "-------------------------------------------------------------"
echo "\033[35;5;5mend of test \033[0m"
echo " "
echo " "
echo " "
echo "\033[36;5;5mvalidation right map \033[0m"
echo "-------------------------------------------------------------"
echo "\033[33mmap 0:easy map \033[0m"
./fdf test/test_map_right/map0
echo " "
echo "\033[33mmap 1:bigger than 0 \033[0m"
./fdf test/test_map_right/map1
echo " "
echo "\033[33mmap 2:differnt numbers of sp\033[0m"
./fdf test/test_map_right/map2
echo " "
echo "\033[33mmap 3:hello one color\033[0m"
./fdf test/test_map_right/map3
echo " "
echo "\033[33mmap 4:colors in two lines\033[0m"
./fdf test/test_map_right/map4
echo " "
echo "\033[33mmap 5:in last line two points with colors\033[0m"
./fdf test/test_map_right/map5
echo " "
echo "\033[33mmap 6:map 10-2 from examples\033[0m"
./fdf test/test_map_right/map6
echo " "
echo "\033[33mmap 7:map 10-70 from examples\033[0m"
./fdf test/test_map_right/map7
echo " "
echo "\033[33mmap 8:42 from examples\033[0m"
./fdf test/test_map_right/map8
echo " "
echo "\033[33mmap 9:basic test fdf\033[0m"
./fdf test/test_map_right/map9
echo " "
echo "\033[33mmap 10:pyramide\033[0m"
./fdf test/test_map_right/map10
echo " "
#echo "\033[33mmap 11:mars\033[0m"
#./fdf test/test_map_right/map11
echo " "
echo "-------------------------------------------------------------"
echo "\033[36;5;5mend of test \033[0m"
