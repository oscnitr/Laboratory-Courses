%%
[a-zA-Z]  { printf("Character"); }
[a-zA-Z]+  { printf("String"); }
.+	{printf("Other symbols"); }
%%

