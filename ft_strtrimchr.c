#include "libft.h"

char    *ft_strtrimchr(const char *s1, int c){
	size_t start;
	size_t end;
	size_t tmp;
	size_t i;
	char	*str;

	start = 0;
	end = ft_strlen_const(s1) - 1;
	i = 0;
	if(s1 == NULL)
		return(NULL);
	while(s1[start] == (unsigned char)c && s1[start] != '\0')
		start++;
	tmp = start;
	while(end > start && s1[end] == (unsigned char)c)
		end--;
	str = (char *)malloc(((end - start) + 2) * sizeof(char));
	if(str == NULL)
		return(NULL);
	while(i < (end - start  + 1)){
		str[i] = s1[tmp];
		i++;
		tmp++;
	}
	str[i] = '\0';
	return(str);
}