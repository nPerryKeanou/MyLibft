#include "libft.h"

size_t	startStr(const char *s1, const char *set){
	size_t i;
	size_t j;
	int isPresent;


	i = 0;
	while(s1[i] != '\0'){
		j = 0;
		isPresent = 0;
		while(set[j] != '\0'){
			if(s1[i] == set[j]){
				isPresent = 1;
				break;
			}
			j++;
		}
		if(isPresent == 0){
			return(i);
		}
		i++;
	}
	return(i);
}

size_t	endStr(const char *s1, const char *set){
	size_t end;
	size_t i;
	int isPresent;

	end = ft_strlen_const(s1);
	printf("end --> len --> %zu\n", end);
	while(end > 0){
		isPresent = 0;
		i = 0;
		while(set[i] != '\0'){
			if(s1[end - 1] == set[i]){
				isPresent = 1;
				break;
			}
			i++;
		}
		if(isPresent == 0){
			return(end);
		}
		end--;
	}
	return(end);
}

char    *ft_strtrimchr_multi(const char *s1, const char    *set){
	size_t start;
	size_t end;
	size_t i;
	char	*str;

	start = startStr(s1, set);
	end = endStr(s1, set);
	i = 0;
	if (start == end) {
        char *emptyStr = (char *)malloc(1);
        if (emptyStr == NULL) {
            return NULL;
        }
        emptyStr[0] = '\0';
        return emptyStr;
    }
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if(str == NULL){
		return(NULL);
	}
	while(start < end){
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return(str);
}   