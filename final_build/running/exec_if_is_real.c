/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if_is_real.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:02:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/21 11:08:20 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				STRUCT STAT


		Estrutura usada para armazenar informacoes de arquivos em sistemas
	UNIX e LINUX.

		Ela contem varios campos com informacoes do arquivo.
	Os mais comuns de usar sao:

		- st_mode: informacoes sobre o tipo de arquivo e permissoes.
		- st_size: Tamanho do arquivo em bytes.
		- st_uid e st_gid: IDs do usuario e do grupo do arquivo, respeivamente.
		- st_atime, st_mtime, st_ctime: Informacoes sobre os tempos de acesso,
	modificacao e mudanca de status do arquivo.

		Ao chamar a funcao stat() em um determinado caminho,
	os detalhes sobre o arquivo no caminho sao preenchidos na
	estrutura 'struct stat'.
*/

/*
				EXEC_IF_IS_REAL


		A funcao interpreta o comando dado em exe.

		INPUT:

			exe - O comando a executar.
			argv - Argumentos do executavel.

		FUNCIONAMENTO:

			1 - A variavel path detera o caminho para o executavel, atraves
		da funcao get_executable_path caso ele exista.

			2 - Com a funcao stat e preenchida a estrutura "stat" demonstarada
		a cima.

			3 - Se path for encontrado, e verificado com o recurso ao MACRO S_ISDIR
		atraves do parametro st_mode da estrutura stat, se o usuario esta a tentar
		executar um diretorio, e caso se verifique o programa escreve uma mensagem de
		erro.

			4 - Caso contrario, e verificado, atraves de outro MACRO, se o executavel
		dado e um ficheiro regular, ou seja, que pode ser lido,
		e se sim, e tentado executar
		com a funcao execve.

				Caso a funcao nao consiga executar o ficheiro,
			e escrita uma mensagem de erro.

			5 - E libertada a memoria de path, caso ele tenha sido criado.'

			6 - Por fim, se nao for encontrado nenhum caminho com o ficheiro que o
		usuario esta a tentar executar, e retornado uma mensagem de erro.


*/

// S_ISDIR(): Macro em C verifica se o modo do arquivo e um diretorio.
// Retorna true caso seja um arquivo e falso caso contrario.
// 126 e o codigo usual de saida do bash, caso haja
// um erro de execucao de um comando que nao foi encontrado.
// Verifica se o arquivo e regular, ou seja uma arquivo comum que pode
		// conter dados.

void	exec_if_is_real(char *exe, char **argv)
{
	char		*path;
	struct stat	stat_path;

	path = get_executable_path(exe);
	if (path)
		stat(path, &stat_path);
	if (path)
	{
		if (S_ISDIR(stat_path.st_mode))
			handle_error("Comando nao encontrado:", exe, 126);
		else if (S_ISREG(stat_path.st_mode))
		{
			execve(path, argv, ms()->env_matrix);
			handle_error("Erro ao tentar executar o comando: ", exe, 126);
		}
		free(path);
	}
	else
	{
		printf("minishell: %s: No such file or directory\n", exe);
		ms()->exit_status = 127;
	}
	return ;
}
