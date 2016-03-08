/*
*    9-4. If a process whose user IDs all have the value X executes a set-user-ID program
*  whose user ID, Y, is nonzero, then the process credentials are set as follows:
*
*       real=X effective=Y saved=Y
*
*  (We ignore the file-system user ID, since it tracks the effective user ID.) Show the
*  setuid(), seteuid(), setreuid(), and setresuid() calls, respectively, that would be used to
*  perform the following operations:
*
*       a) Suspend and resume the set-user-ID identity (i.e., switch the effective user
*       ID to the value of the real user ID and then back to the saved set-user-ID).
*
*       b) Permanently drop the set-user-ID identity (i.e., ensure that the effective
*       user ID and the saved set-user-ID are set to the value of the real user ID).
*
*  (This exercise also requires the use of getuid() and geteuid() to retrieve the process’s
*  real and effective user IDs.) Note that for certain of the system calls listed above,
*  some of these operations can't be performed.
*/

/*
   a) uid_t tempeuid = geteuid();

      setuid(getuid());
      setuid(tempeuid);

      seteuid(getuid());
      seteuid(tempeuid);

      setreuid(-1, getuid();
      setreuid(-1, tempeuid);

      setresuid(-1, getuid(), -1);
      setresuid(-1, tempeuid, -1);

   b) setreuid(getuid(), getuid());
      setresuid(getuid(), getuid(), getuid());
   
*/