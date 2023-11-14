/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:41:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/09/19 14:31:05 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
				ACESS

	Funcao utitlizada para verififcar se o processo tem
	permissoes especificas para aceder a um arquivo ou diretorio.

		int access(const char *path, int mode);

			INPUT:

				path: Caminho do arquivo ou diretorio a verificar.
				mode: O modo de acesso que se quer verificar.

					MODOS:
						R_OK : Verifica se o arquivo pode ser lido
						W_OK : Verifica se pode ser escrito.
						X_OK : Verifica se o arquivo pode ser executado.
						F_OK: Veriifca se o arquivo existe.

			RETORNO:

				Retorna 0 caso o acesso seja permitido e -1 caso contrario.
*/

/*
				GET_ABSOLUTE_PATH


		Esta funcao retorna, caso seja possivel, o caminho absoluto
	do executavel dado pelo usuario.

		FUNCIONAMENTO:

			1 - Se exe estiver vazia e logo retornado NULL.

			2 - Com a funcao acess, e verificado se o exe dado ja e
		o caminho absoluto do comando, ou seja, se o executavel ja existe
		na pasta atual.
				Caso se verifique isso, a funcao retorna uma string
		com o nome dado pelo o usuario, sendo este o caminho para o
		executavel.

			3 - Se o ponto dois nao se verificar, vamos comecar a
		procurar nos varios diretorios que a variavel path nos indica
		para ver se o executavel esta em algum deles. E iterada a variavel
		path, para verificar nos diferentes caminhos, atraves da funcao
		acess, se em algum dele e possivel executar o comando dado
		e em caso da funcao acess dar o seu aval, e retornado o path correto
		para esse comando.

			4 - Se nao for encontrado nenhum caminho absoluto valido,
		a funcao retorna NULL.
*/
char	*get_absolute(char *exe)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	if (exe[0] == '\0')
		return (NULL);
	if (access(exe, F_OK) == 0)
	{
		path = ft_strjoin("", exe);
		return (path);
	}
	if (!ms()->path)
		return (NULL);
	while (ms()->path[i])
	{
		tmp = ft_strjoin(ms()->path[i], "/");
		path = ft_strjoin(tmp, exe);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

/*
				GET_RELATIVE


		Em get_relative tentamos retornar o caminho relativo
	do executavel dado.

		INPUT:

			Recebe o novo do executavel.

		FUNCIONAMENTO:

			1 - char *tmp e criada para armezenar o caminho atual
		com uma barra no final. Numenclatura dos caminhos.

			2 - parh e criada para armazenar o caminho do executavel
		dado pelo o usuario, que normalmente comeca com './', e por isso
		ao juntar esse caminho ao atual, e avancado 2 caracteres no exe
		dado pelo usuario.

			3 - Com a funcao acess e verificado entao, se e permitido
		o acesso a esse executavel com o caminho dado, caso seja o caminho
		e retornado.

			4 - Se o ponto 3 nao se verificar e entao libertada a varivel path
		e e verificado se e possivel aceder ao executavel apenas com o
		input do usuario, e caso isso se verifique e retornado uma copia
		do input dado pelo usuario.

			5 - Caso nao seja possivel, e retornado NULL.
*/

char	*get_relative(char *exe)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(ms()->pwd, "/");
	path = ft_strjoin(tmp, exe + 2);
	free(tmp);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	if (access(exe, F_OK) == 0)
		return (ft_strdup(exe));
	return (NULL);
}

/*
				GET_EXECUTABLE_PATH


		A funcao get_executable_path tem como objetivo retornar
	o caminho de um executavel.

		INPUT:

			Recebe o nome do executavel.

		Funcionamento:

			1 - Em primeira instancia, e verificado se o primeiro
		caractere de exe.
				Caso se confirme, e chamada a funcao get_relativo,
			para tentar obter o caminho relativo do executavel.

			2 - Caso o ponto 1 nao seja verificado e chamada a funcao
		get_absolute, para tentar obter o caminho absoluto do executavel.

		RETORNO:

			Retorna o caminho obtido.

*/

char	*get_executable_path(char *exe)
{
	char	*path;

	if (exe[0] == '.')
		path = get_relative(exe);
	else
		path = get_absolute(exe);
	return (path);
}
