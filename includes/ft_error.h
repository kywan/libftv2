/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:52:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/19 17:24:55 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

// penser a faire l'imcompatibilité de # avec la majorité des types.
// plus 0 + et - qui ne marche pas avec certain type (ex : s)
enum e_error
{
	no_error,
	incompflag_zeromoins,
	incompflag_spaceplus,
	invalid_type,
	badmodif,
};
#endif
