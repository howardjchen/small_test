# small_test

## Memoery leak test
- test_mem_leak.c is a code for testing memoery leak.
- You could use valgrind to check
```shell
gcc -o test_mem_leak test_mem_leak.c
valgrind --tool=memcheck --leak-check=full --track-origins=yes ./test_mem_leak
```
- You will see the report from valgrind like below,
```
==7049==
==7049== HEAP SUMMARY:
==7049==     in use at exit: 0 bytes in 0 blocks
==7049==   total heap usage: 13 allocs, 13 frees, 1,224 bytes allocated
==7049==
==7049== All heap blocks were freed -- no leaks are possible
==7049==
==7049== For lists of detected and suppressed errors, rerun with: -s
==7049== ERROR SUMMARY: 130 errors from 8 contexts (suppressed: 0 from 0)
```



