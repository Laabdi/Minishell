/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:54:53 by aelomari          #+#    #+#             */
/*   Updated: 2024/12/02 23:48:52 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "includes.h"

void		free_env(t_env **env);
void		free_outfiles_list(t_outfile **s_outfile);
void		free_infiles_list(t_infile **infile);
void		print_error(char *error, char *arg);
// linked list;
int			list_size(t_env **env);
t_env		*creat_list(void);
t_env		*get_last_node(t_env **lst);
void		ft_lstadd_backk(t_env **lst, t_env *new);
void		print_stack(t_env **lst);
void		free_env_list(t_env **env);
// env;
int			var_without_equal(char *s);
void		update_old_path(t_env **env, char *old_path);
void		update_new_path(t_env **env, char *new_path);
char		*get_old_path(void);
char		*get_new_path(void);
void		store_in_env(char *s, t_env *envp);
void		ft_env_add(t_env **env, char *name, char *value);
void		parse_env_vars(char **env);
void		ft_swap(t_env *env, t_env *to_swap);
void		env_sort(t_env **env);
void		print_exportng(t_env *env);
// export
int			var_without_equal(char *s);
char		*get_variable_value(char *s);
char		*get_variable_name(char *s);
void		ft_remove(t_env **env, t_env *to_remove);
int			is_exportable(char *s);
int			is_valid_unset_input(t_env **env, char *av);
int			already_exist(t_env *env, char *s);
void		update_env(char *s, t_env *env);
int			check_export_with_plus(char *av);
void		export_with_plus(t_env **env, char *av);
char		*get_variable_name(char *s);
void		export_to_env(char **s, t_env **env);
void		my_cd(char **av, t_env **env);
void		ft_unset(t_env **env, char **av);
t_env		*get_envp(char **env);
void		ignore_inside(t_var *var);
void		handle_sigquit(int signal);
int			process_infile(t_words **words, char *line, int i);
int			count_delimiter_chars(const char *line, int i);
int			is_balanced_quotes(const char *line);
void		free_pipeline(t_pipeline *pipeline);
void		quoting_str(char **line);
void		free_words(t_words *words);
void		quoting(t_var *var);
void		safe_free(char **ptr);
void		free_string_array(char ***array);
void		remove_quotes(t_words *words);
void		*ft_malloc(size_t size);
void		check_syntax(t_var *var);

void		pipe_addback(t_pipeline **pipel, t_pipeline *new);
void		free_pipeline(t_pipeline *pipeline);
t_pipeline	*parser(t_var *var);
void		lexer(t_var *var);
void		check_redirect(t_var *var);
void		check_pipes(t_var *var);
void		thisisasynerror(t_syntax_error error);
void		check_quoting(t_var *var);
void		ignore_inside(t_var *var);
void		print_env(char **env);
void		replace_between_quotes(t_var *var);
void		quoting(t_var *var);
void		between_quote(char *line);
void		envcpy(char **enver, char **env);
void		init(t_var *var, int ac, char **av, char **env);
int			darr_count(char **arr);
void		ft_pwd(void);
void		ft_env(void);
char		*ft_strdup(const char *s);
void		sig_handler(int signo);
void		*free_all(char **sp);
void		expand_env_vars(char **line);
void		print_env(char **env);
t_var		*get_var(void);
void		ft_echo(char **args);
void		parse_outfiles_and_append(t_words **words, char *line);
void		execute(t_var *var);
t_pipeline	*pipe_addnew(t_words *words);
void		parse_infiles_and_heredocs(t_words **words, char *line);
void		add_to_outfiles(t_outfile **outfiles, char *filename,
				t_red_type type, bool is_amred);
void		add_to_infiles(t_infile **infiles, char *filename, t_red_type type,
				char *delimiter);
char		*read_heredoc(char *delimiter);
char		*create_heredoc_filename(int count);
void		ft_exit(char **args);
void		signals(void);
// execution
int			open_file(char *filename, t_file_mode mode);
void		redirect_fd(int old_fd, int new_fd);
void		handle_heredoc(t_infile *infile);
void		handle_input_redirection(t_pipeline *pipeline);
void		handle_output_redirection(t_pipeline *pipeline);
int			darr_count(char **arr);
char		*handle_path_error(char *cmd);
char		*handle_special_cmd_error(char *cmd);
char		*search_cmd_in_paths(char *cmd, char **paths);
char		*get_cmd(char *cmd);
void		return_status(t_var *var, pid_t **pids);
void		close_all_pipes(int **pipes, int count);
int			**make_pipes(int count);
int			pipe_count(t_pipeline *pipeline);
char		**handle_cmd(t_pipeline *pipeline);
int			is_builtin(t_words *words);
bool		handle_single_builtin(t_pipeline *pipeline);
void		setup_child_pipes(t_pipeline *pipeline, t_pipe_info *pipe_info);
char		*create_env_str(char *name, char *value);
char		**env_to_array(t_env *envp);
void		free_child_resources(t_var *var, char **cmd, char **env);
void		sig_hh(int test);
void		sig_hhh(int hhh);
#endif