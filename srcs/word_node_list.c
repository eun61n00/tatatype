#include <stdlib.h>
#include "../includes/tatatype.h"

word_node	*ft_lstnew();
word_node	*ft_lstlast(word_node *lst);
void	ft_lstadd_back(word_node **lst, word_node *new);

char *random_word() {
	char *words[] = { "useless", "alone", "athwart", "lest", "blah",
					"as long as", "cruelly", "punctually", "until", "strand",
					"since", "naturally", "regret", "mmm", "as though", "in order that",
					"now", "failing", "champion", "so that", "because", "sheepishly", "graceful",
					"plush", "if then", "inasmuch", "knee", "guilty", "even", "grubby",
					"incarnate", "supposing", "dead", "deaden", "tactics", "miserly",
					"notwithstanding", "guide", "about", "public", "afore", "er", "ugh",
					"generously", "huzzah", "station", "painfully", "even though", "aw",
					"woot", "upstage", "brr", "especially", "noteworthy", "during", "aware",
					"however", "bunker", "if only", "squiggly", "given", "owl", "greatly",
					"to", "yuck", "coverall", "barring", "forfend", "yowza", "frightened",
					"mediocre", "oak", "joyously", "crafty", "ah", "finally", "yet",
					"cheerfully", "hm", "director", "jib", "as long as", "parched", "authorized",
					"dismount", "squiggly", "finally", "aha", "bah", "consequently", "so",
					"gadzooks", "memorable", "unfortunately", "bamboo", "because", "jaunty",
					"since", "sure-footed", "vivaciously"
	};
	// printf("%d\n", rand() % 100);
	// printf("%s\n", words[rand() % 100]);
	return words[rand() % 100];
}

word_node	*make_word_node_list() {
	word_node *ret;
	word_node *tmp;
	int i;

	ret = ft_lstnew();
	for (i = 0; i < 100; i++) {
		tmp = ft_lstnew();
		ft_lstadd_back(&ret, tmp);
	}
	return ret;
}

word_node	*ft_lstnew()
{
	word_node	*ret;

	ret = (word_node *)malloc(sizeof(word_node));
	if (ret == NULL)
		return (NULL);
	ret->string = random_word();
	ret->next = NULL;
	return (ret);
}

word_node	*ft_lstlast(word_node *lst)
{
	word_node	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(word_node **lst, word_node *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
