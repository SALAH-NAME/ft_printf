#include "./ft_printf.h"

void	ft_test_c(void)
{
	int	n;

	printf("\nprintf(\"%%c\", 65); => ");
	n = printf("%c", 65);
	printf("\nreturned => %d\n", n);
	printf("\nft_printf(\"%%c\", 65); => ");
	fflush(stdout);
	n = ft_printf("%c", 65);
	printf("\nreturned => %d\n", n);
	printf("\nprintf(\"%%c\", 7); => ");
	n = printf("%c", 7);
	printf("\nreturned => %d\n", n);
	printf("\nprintf(\"%%c\", 7); => ");
	fflush(stdout);
	n = ft_printf("%c", 7);
	printf("\nreturned => %d\n", n);
	printf("\nprintf(\"%%%%c\"); => ");
	n = printf("%%c");
	printf("\nreturned => %d\n", n);
	printf("\nprintf(\"%%%%c\"); => ");
	fflush(stdout);
	n = ft_printf("%%c");
	printf("\nreturned => %d\n", n);
	printf("\nprintf(\"%%c\", 0); => ");
	n = printf("%c", 0);
	printf("\nreturned => %d\n", n);
	printf("\nprintf(\"%%c\", 0); => ");
	fflush(stdout);
	n = ft_printf("%c", 0);
	printf("\nreturned => %d\n", n);
}

int	main(void)
{
	ft_test_c();
	return (0);
}
