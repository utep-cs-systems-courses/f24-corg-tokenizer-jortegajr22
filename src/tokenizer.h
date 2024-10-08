#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return !space_char(c) && c != '\0';
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while (*str != '\0' || space_char(*str))
    {
      str++;
    }
  if (*str == '\0'){
    return NULL;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  while (*token != '\0' && non_space_char(*token){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int count = 0;
  char *token = token_start(str);
  while (token != NULL){
    count++;
    token = token_start(token_terminator(token));
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *new_str = (char *)malloc((len +1) * sizeof(char)); //memory allocation size of inStr+1

  for(short i = 0; i < len; i++){
    new_str[i] = inStr[i];
  }
  new_str[len] = '\0';
  
  return new_str;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  // malloc # of tokens+1
  int count = count_tokens(str);
  char **tokens = (char **)malloc((count+1) * sizeof(char *));

  int t_index = 0;
  char *token = token_start(str);

  //loop through string and extract tokens
  while (token != NULL){
    char *end_token = token_terminator(token);
    int len = end_token - token;
    tokens[t_index] = copy_str(token, len);
    if (tokens[t_index] == NULL){
      printf("Malloc fail");

      return NULL;
    }
    t_index++;
    token = token_start(end_token);
  }
  tokens[t_index] = NULL;
  //find out how to free up array of tokens
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  while (tokens[i] != NULL) {
    printf("tokens[%d] = '%s'\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  //loop through tokens and free memory for each
  int i = 0;
  while (tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}

#endif
