/*
*  9-5. Repeat the previous exercise (Ex9-4) for a process executing a set-user-ID-root program,
*  which has the following initial set of process credentials:
*
*       real=X effective=0 saved=0
*/

/*
   a) seteuid(getuid());
      seteuid(0);

      setreuid(-1, getuid();
      setreuid(-1, 0);

      setresuid(-1, getuid(), -1);
      setresuid(-1, 0, -1);

   b) setuid(getuid());
      setreuid(getuid(), getuid());
      setresuid(getuid(), getuid(), getuid());
      
*/