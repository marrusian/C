/*
*  9-2. Is a process with the following user IDs privileged? Explain your answer.
*
*         real=0  effective=1000  saved=1000  file-system=1000
*/

/*
*   Technically speaking, it is NOT privileged, ALTHOUGH it belongs to the "root" user (the superuser).
*   However, it is POTENTIALLY PRIVILEGED, because it can make a call such as seteuid(getuid()) in order
*  in order to gain SUPERUSER PRIVILEGES. 
*/

