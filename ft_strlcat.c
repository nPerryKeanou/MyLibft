#include "libft.h"

size_t ft_strlcat(char	*dst, const char	*src, size_t dstsize){
	size_t len_dst;
	size_t len_src;
	size_t i;
	size_t j;
	size_t rest;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen_const(src);
	if(dst != NULL && src != NULL && dstsize > 0){
		rest = dstsize - len_dst - 1;
		i = len_dst;
		j = 0;
		while(j < rest && src[j] != '\0'){
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return(len_dst + len_src);
	}else{
		return(len_dst + len_src);
	}
	return(0);
}