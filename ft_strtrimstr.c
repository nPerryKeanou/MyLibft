#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

size_t ft_startingtrim(const char *paramS1,  const char *paramSet){
	size_t rslt;
	size_t i;
	size_t j;
	size_t len_set;

	rslt = 0;
	i = 0;
	j = 0;
	len_set = ft_strlen_const(paramSet);
	while(paramS1[i] != '\0' && paramS1[i] == paramSet[j]){
		if(paramS1[i] == paramSet[j] && j == len_set - 1){
			rslt += 1;
			j = 0;
		}else if(paramS1[i] == paramSet[j] && j < len_set - 1){
			j++;
		}
		else{
			return(rslt);
		}
		i++;
	}
	return(rslt * len_set);
}

size_t ft_endingtrim(const char *paramS1, const char *paramSet){
	size_t rslt;
	size_t i;
	size_t j;
	size_t len_s1;
	size_t len_set;
	int booleTrue;

	rslt = 0;
	i = 0;
	j = 1;
	booleTrue = 1;
	len_s1= ft_strlen_const(paramS1);
	len_set = ft_strlen_const(paramSet);
	while(booleTrue == 1){
		if(paramS1[len_s1 - (len_set * j)] == paramSet[i] && i == len_set - 1){
			rslt += 1;
			i = 0;
			len_s1 -= len_set;
			j++;
		}else if(paramS1[len_s1 - len_set - 1] == paramSet[i] && i < len_set){
			len_s1--;
		}else{
			booleTrue = 0;
			return(rslt);
		}
		i++;
	}
	return(rslt * ft_strlen_const(paramSet));
}

char    *ft_strtrimstr(const char *s1, const char    *set){
	size_t i;
	size_t start;
	size_t end;
	size_t total;
	char	*str;

	i = 0;
	if(s1[i] != set[i]){
		start = 0;
	}else{
		start = ft_startingtrim(s1,  set);
	}
	if(s1[ft_strlen_const(s1) - ft_strlen_const(set)] != set[i]){
		end = 0;
	}else{
		end = ft_endingtrim(s1, set);
	}
	str = (char *)malloc(ft_strlen_const(s1) - start - end + 1 * sizeof(char));
	if(str == NULL){
		return(NULL);
	}
	total = ft_strlen_const(s1) - start - end - 1;
	while(s1[i] != '\0' && i < total){
		str[i] = s1[start];
		i++;
		start++; 
	}
	str[i] = '\0';
	return(str);

	/**
	 *     
	size_t i = 0;
    size_t start = (s1[i] != set[i]) ? 0 : ft_startingtrim(s1, set);
    size_t end = (s1[ft_strlen_const(s1) - ft_strlen_const(set)] != set[i]) ? 0 : ft_endingtrim(s1, set);
    size_t total = ft_strlen_const(s1) - start - end - 1;
    char *str = (char *)malloc((total + 1) * sizeof(char));

    if (str == NULL) {
        return NULL;
    }

    while (s1[i] != '\0' && i < total) {
        str[i] = s1[start];
        i++;
        start++;
    }

    str[i] = '\0';

    return str;
	*/
}   