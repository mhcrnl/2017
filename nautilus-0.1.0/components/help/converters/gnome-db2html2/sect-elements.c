#include <config.h>
#include "sect-elements.h"
#include "gnome.h"

#define IS_IN_SECT(context) (((SectContext *)context->data)->state == IN_SECT)

ElementInfo sect_elements[] = {
	{ ARTICLE, "article", (startElementSAXFunc) article_start_element, (endElementSAXFunc) sect_article_end_element, NULL},
	{ BOOK, "book", NULL, NULL, NULL},
	{ SECTION, "section", (startElementSAXFunc) sect_sect_start_element, (endElementSAXFunc) sect_sect_end_element, NULL},
	{ SECT1, "sect1", (startElementSAXFunc) sect_sect_start_element, (endElementSAXFunc) sect_sect_end_element, NULL},
	{ SECT2, "sect2", (startElementSAXFunc) sect_sect_start_element, (endElementSAXFunc) sect_sect_end_element, NULL},
	{ SECT3, "sect3", (startElementSAXFunc) sect_sect_start_element, (endElementSAXFunc) sect_sect_end_element, NULL},
	{ SECT4, "sect4", (startElementSAXFunc) sect_sect_start_element, (endElementSAXFunc) sect_sect_end_element, NULL},
	{ SECT5, "sect5", (startElementSAXFunc) sect_sect_start_element, (endElementSAXFunc) sect_sect_end_element, NULL},
	{ PARA, "para", (startElementSAXFunc) sect_para_start_element, (endElementSAXFunc) sect_para_end_element, (charactersSAXFunc) sect_write_characters},
	{ FORMALPARA, "formalpara", (startElementSAXFunc) sect_formalpara_start_element, (endElementSAXFunc) sect_formalpara_end_element, NULL },
	{ BOOKINFO, "bookinfo", NULL, NULL, NULL},
	{ ARTHEADER, "artheader", NULL, NULL, NULL}, //(startElementSAXFunc) artheader_start_element, (endElementSAXFunc) sect_artheader_end_element, NULL},
	{ ARTICLEINFO, "articleinfo", NULL, NULL, NULL},
	{ AUTHORGROUP, "authorgroup", NULL, NULL, NULL},
	{ AUTHOR, "author", (startElementSAXFunc) sect_author_start_element, NULL, NULL},
	{ FIRSTNAME, "firstname", NULL, NULL, (charactersSAXFunc) sect_author_characters },
	{ OTHERNAME, "othername", NULL, NULL, (charactersSAXFunc) sect_author_characters },
	{ SURNAME, "surname", NULL, NULL, (charactersSAXFunc) sect_author_characters },
	{ AFFILIATION, "affiliation", NULL, NULL, NULL},
	{ EMAIL, "email", NULL, NULL, (charactersSAXFunc) sect_email_characters },
	{ ORGNAME, "orgname", NULL, NULL, (charactersSAXFunc) sect_author_characters },
	{ ADDRESS, "address", NULL, NULL, NULL},
	{ COPYRIGHT, "copyright", NULL, NULL, NULL},
	{ YEAR, "year", NULL, NULL, (charactersSAXFunc) sect_copyright_characters},
	{ HOLDER, "holder", NULL, NULL, (charactersSAXFunc) sect_copyright_characters},
	{ TITLE, "title", (startElementSAXFunc) sect_title_start_element, (endElementSAXFunc) sect_title_end_element, (charactersSAXFunc) sect_title_characters },
	{ SUBTITLE, "subtitle", (startElementSAXFunc) sect_title_start_element, (endElementSAXFunc) sect_title_end_element, (charactersSAXFunc) sect_title_characters },
	{ ULINK, "ulink", (startElementSAXFunc) sect_ulink_start_element, (endElementSAXFunc) sect_ulink_end_element, (charactersSAXFunc) sect_write_characters},
	{ XREF, "xref", (startElementSAXFunc) sect_xref_start_element, NULL, NULL},
	{ FOOTNOTE, "footnote", (startElementSAXFunc) sect_footnote_start_element, NULL, NULL},
	{ FIGURE, "figure", (startElementSAXFunc) sect_figure_start_element, (endElementSAXFunc) sect_figure_end_element, NULL},
	{ GRAPHIC, "graphic", (startElementSAXFunc) sect_graphic_start_element, NULL, NULL},
	{ CITETITLE, "citetitle", (startElementSAXFunc) sect_i_start_element, (endElementSAXFunc) sect_i_end_element, (charactersSAXFunc) sect_write_characters},
	{ APPLICATION, "application", (startElementSAXFunc) sect_tt_start_element, (endElementSAXFunc) sect_tt_end_element, (charactersSAXFunc) sect_write_characters},
	{ FILENAME, "filename", (startElementSAXFunc) sect_tt_start_element, (endElementSAXFunc) sect_tt_end_element, (charactersSAXFunc) sect_write_characters},
	{ ITEMIZEDLIST, "itemizedlist", (startElementSAXFunc) sect_itemizedlist_start_element, (endElementSAXFunc) sect_itemizedlist_end_element, NULL},
	{ ORDEREDLIST, "orderedlist", (startElementSAXFunc) sect_orderedlist_start_element, (endElementSAXFunc) sect_orderedlist_end_element, NULL},
	{ VARIABLELIST, "variablelist", (startElementSAXFunc) sect_variablelist_start_element, (endElementSAXFunc) sect_variablelist_end_element, NULL},
	{ LISTITEM, "listitem", (startElementSAXFunc) sect_listitem_start_element, (endElementSAXFunc) sect_listitem_end_element, NULL},
	{ PROGRAMLISTING, "programlisting", (startElementSAXFunc) sect_programlisting_start_element, (endElementSAXFunc) sect_programlisting_end_element, (charactersSAXFunc) sect_write_characters},
	{ SGMLTAG, "sgmltag", (startElementSAXFunc) sect_tt_start_element, (endElementSAXFunc) sect_tt_end_element, (charactersSAXFunc) sect_write_characters},
	{ EMPHASIS, "emphasis", (startElementSAXFunc) sect_em_start_element, (endElementSAXFunc) sect_em_end_element, (charactersSAXFunc) sect_write_characters},
	{ TIP, "tip", (startElementSAXFunc) sect_infobox_start_element, (endElementSAXFunc) sect_infobox_end_element, NULL},
	{ WARNING, "warning", (startElementSAXFunc) sect_infobox_start_element, (endElementSAXFunc) sect_infobox_end_element, NULL},
	{ IMPORTANT, "important", (startElementSAXFunc) sect_infobox_start_element, (endElementSAXFunc) sect_infobox_end_element, NULL},
	{ NOTE, "note", (startElementSAXFunc) sect_infobox_start_element, (endElementSAXFunc) sect_infobox_end_element, NULL},
	{ CDATA, "cdata", NULL, NULL, (charactersSAXFunc) sect_cdata_characters},
	{ SCREEN, "screen", (startElementSAXFunc)sect_programlisting_start_element, (endElementSAXFunc) sect_programlisting_end_element, (charactersSAXFunc) sect_write_characters},
	{ SCREENSHOT, "screenshot", NULL, NULL, NULL},
	{ SCREENINFO, "screeninfo", NULL, NULL, NULL},
	{ COMMAND, "command", (startElementSAXFunc) sect_b_start_element, (endElementSAXFunc) sect_b_end_element, (charactersSAXFunc) sect_write_characters},
	{ REPLACEABLE, "replaceable", (startElementSAXFunc) sect_tti_start_element, (endElementSAXFunc) sect_tti_end_element, (charactersSAXFunc) sect_write_characters},
	{ FUNCTION, "function", (startElementSAXFunc) sect_tt_start_element, (endElementSAXFunc) sect_tt_end_element, (charactersSAXFunc) sect_write_characters},
	{ GUIBUTTON, "guibutton", (startElementSAXFunc) sect_b_start_element, (endElementSAXFunc) sect_b_end_element, (charactersSAXFunc) sect_write_characters},
	{ GUIICON, "guiicon", (startElementSAXFunc) sect_b_start_element, (endElementSAXFunc) sect_b_end_element, (charactersSAXFunc) sect_write_characters},
	{ GUILABEL, "guilabel", (startElementSAXFunc) sect_btt_start_element, (endElementSAXFunc) sect_btt_end_element, (charactersSAXFunc) sect_write_characters},
	{ GUIMENU, "guimenu", (startElementSAXFunc) sect_menu_start_element, (endElementSAXFunc) sect_menu_end_element, (charactersSAXFunc) sect_write_characters},
	{ GUIMENUITEM, "guimenuitem", (startElementSAXFunc) sect_b_start_element, (endElementSAXFunc) sect_b_end_element, (charactersSAXFunc) sect_write_characters},
	{ HARDWARE, "hardware", (startElementSAXFunc) sect_btt_start_element, (endElementSAXFunc) sect_btt_end_element, (charactersSAXFunc) sect_write_characters},
	{ KEYCAP, "keycap", (startElementSAXFunc) sect_b_start_element, (endElementSAXFunc) sect_b_end_element, (charactersSAXFunc) sect_write_characters},
	{ KEYCAP, "keycode", NULL, NULL, (charactersSAXFunc) sect_write_characters},
	{ KEYCAP, "keysym", (startElementSAXFunc) sect_keysym_start_element, (endElementSAXFunc) sect_keysym_end_element, (charactersSAXFunc) sect_write_characters},
	{ LITERAL, "literal", (startElementSAXFunc) sect_tt_start_element, (endElementSAXFunc) sect_tt_end_element, (charactersSAXFunc) sect_write_characters},
	{ PARAMETER, "parameter", (startElementSAXFunc) sect_tti_start_element, (endElementSAXFunc) sect_tti_end_element, (charactersSAXFunc) sect_write_characters},
	{ PROMPT, "prompt", (startElementSAXFunc) sect_tt_start_element, (endElementSAXFunc) sect_tt_end_element, (charactersSAXFunc) sect_write_characters},
	{ SYMBOL, "symbol", NULL, NULL, (charactersSAXFunc) sect_write_characters},
	{ USERINPUT, "userinput", (startElementSAXFunc) sect_btt_start_element, (endElementSAXFunc) sect_btt_end_element, (charactersSAXFunc) sect_write_characters},
	{ CAUTION, "caution", (startElementSAXFunc) sect_infobox_start_element, (endElementSAXFunc) sect_infobox_end_element, NULL},
	{ LEGALPARA, "legalpara", NULL, NULL, NULL},
	{ FIRSTTERM, "firstterm", (startElementSAXFunc) sect_em_start_element, (endElementSAXFunc) sect_em_end_element, (charactersSAXFunc) sect_write_characters},
	{ STRUCTNAME, "structname", NULL, NULL, (charactersSAXFunc) sect_write_characters},
	{ STRUCTFIELD, "structfield", NULL, NULL, (charactersSAXFunc) sect_write_characters},
	{ FUNCSYNOPSIS, "funcsynopsis", (startElementSAXFunc) sect_funcsynopsis_start_element, (endElementSAXFunc) sect_funcsynopsis_end_element, NULL},
	{ FUNCPROTOTYPE, "funcprototype", (startElementSAXFunc) sect_funcprototype_start_element, NULL, NULL},
	{ FUNCDEF, "funcdef", NULL, NULL, (charactersSAXFunc) sect_write_characters},
	{ FUNCPARAMS, "funcparams", (startElementSAXFunc) sect_funcparams_start_element, (endElementSAXFunc) sect_funcparams_end_element, (charactersSAXFunc) sect_write_characters},
	{ PARAMDEF, "paramdef", (startElementSAXFunc) sect_paramdef_start_element, NULL, (charactersSAXFunc) sect_write_characters},
	{ VOID, "void", (startElementSAXFunc) sect_void_start_element, NULL, NULL },
	{ GUISUBMENU, "guisubmenu", (startElementSAXFunc) sect_menu_start_element, (endElementSAXFunc) sect_menu_end_element, (charactersSAXFunc) sect_write_characters},
	{ INTERFACE, "interface", (startElementSAXFunc) sect_interface_start_element, (endElementSAXFunc) sect_interface_end_element, (charactersSAXFunc) sect_write_characters},
	{ LINK, "link", (startElementSAXFunc) sect_link_start_element, (endElementSAXFunc) sect_link_end_element, (charactersSAXFunc) sect_write_characters},
	{ MENUCHOICE, "menuchoice", NULL, NULL, NULL},
	{ UNDEFINED, NULL, NULL, NULL, NULL}
};

void
sect_print (Context *context, gchar *format, ...)
{
	va_list args;
	gchar *string;
	GSList *list;
	ElementIndex index;
	GString *footnote;
	SectFuncProtoInfo *proto;
	StackElement *stack_el;

	g_return_if_fail (format != NULL);

	va_start (args, format);
	string = g_strdup_vprintf (format, args);
	va_end (args);

	list = g_slist_prepend (NULL, GINT_TO_POINTER (FOOTNOTE));
	list = g_slist_prepend (list, GINT_TO_POINTER (FUNCPROTOTYPE));
	list = g_slist_prepend (list, GINT_TO_POINTER (FUNCDEF));
	list = g_slist_prepend (list, GINT_TO_POINTER (PARAMDEF));
	index = find_first_parent (context, list);

	switch (index) {
	case FUNCDEF:
		stack_el = (StackElement *) context->stack->data;
		if (stack_el->info->index == FUNCTION) {
			list = g_slist_last (((SectContext *)(context->data))->func_synopsis);
			proto = (SectFuncProtoInfo *) list->data;
			if (proto->func)
				g_string_append (proto->func, string);
			else
				proto->func = g_string_new (string);
			g_free (string);
		} else {
			list = g_slist_last (((SectContext *)(context->data))->func_synopsis);
			proto = (SectFuncProtoInfo *) list->data;
			if (proto->retval)
				g_free (string);
			else
				proto->retval = string;
		}
		break;
	case PARAMDEF:
		list = g_slist_last (((SectContext *)(context->data))->func_synopsis);
		proto = (SectFuncProtoInfo *) list->data;
		list = g_slist_last (proto->params);
		if (list->data) {
			GString *gstr = (GString *) list->data;
			g_string_append (gstr, string);
		}
		break;
	case FOOTNOTE:
		list = g_slist_last (context->footnotes);
		footnote = (GString *) list->data;
		g_string_append (footnote, string);
		g_free (string);
		break;
	case FUNCPROTOTYPE:
		stack_el = (StackElement *) context->stack->data;
		if (stack_el->info->index == VOID) {
			list = g_slist_last (((SectContext *)(context->data))->func_synopsis);
			proto = (SectFuncProtoInfo *) list->data;
			if (proto->params == NULL) {
				proto->params = g_slist_append (proto->params,
							       g_string_new (string));
			} /* else <void> was incorrectly used */
		}
		g_free (string);
		break;
	default:
		if ((*string == '<') && (*(string +1) == '\000'))
			printf ("&lt;");
		else if ((*string == '&') && (*(string +1) == '\000'))
			printf ("&amp;");
		else
			printf (string);
		g_free (string);
	}
}

gpointer
sect_init_data (void)
{
	SectContext *retval = g_new0 (SectContext, 1);
	retval->header = g_new0 (HeaderInfo, 1);
	retval->state = LOOKING_FOR_SECT;
	retval->title_hash = g_hash_table_new (g_str_hash,
					       g_str_equal);
	return (gpointer) retval;
}

void
sect_write_characters (Context *context,
		      const gchar *chars,
		      int len)
{
	gchar *temp;

	if (!IS_IN_SECT (context))
		return;

	temp = g_strndup (chars, len);
	sect_print (context, temp);
	g_free (temp);
}

void
sect_article_end_element (Context *context, const gchar *name)
{
	if (context->footnotes) {
		GSList *list;
		gint i = 1;
		
		g_print ("<HR>");
		g_print ("<H4>Notes:</H4>");
		g_print ("<TABLE BORDER=\"0\" WIDTH=\"100%%\">\n\n");
		for (list = context->footnotes; list; list = list->next) {
			g_print ("<TR><TD ALIGN=\"LEFT\" VALIGN=\"TOP\" WIDTH=\"5%%\">\n");
			g_print ("<A HREF=\"#HEADNOTE%d\" NAME=\"FOOTNOTE%d\">[%d]</A></TD>\n", i, i, i);
			g_print ("<TD ALIGN=\"LEFT\" VALIGN=\"TOP\" WIDTH=\"95%%\">\n%s\n</TD></TR>\n", ((GString *)list->data)->str);
			i++;
		}
		g_print ("</TABLE>");
	}
	sect_print (context, "</BODY>\n</HEAD>\n");
}

void
sect_para_start_element (Context *context, const gchar *name, const xmlChar **atrs)
{
	GSList *element_list = NULL;
	StackElement *stack_el;

	if (!IS_IN_SECT (context))
		return;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FIGURE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FOOTNOTE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FORMALPARA));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (LISTITEM));
	stack_el = find_first_element (context, element_list);

	g_slist_free (element_list);
	if (stack_el == NULL)
		return;

	switch (stack_el->info->index) {
	case SECT1:
	case SECT2:
	case SECT3:
	case SECT4:
	case SECT5:
	case SECTION:
		sect_print (context, "<P>\n");
		break;
	case FORMALPARA:
	case LISTITEM:
	default:
		break;
	};
}

void
sect_para_end_element (Context *context, const gchar *name)
{
	GSList *element_list = NULL;
	StackElement *stack_el;

	if (!IS_IN_SECT (context))
		return;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FIGURE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FOOTNOTE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FORMALPARA));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (LISTITEM));
	stack_el = find_first_element (context, element_list);

	g_slist_free (element_list);
	if (stack_el == NULL)
		return;

	switch (stack_el->info->index) {
	case SECT1:
	case SECT2:
	case SECT3:
	case SECT4:
	case SECT5:
	case SECTION:
		sect_print (context, "</P>\n");
		break;
	case FORMALPARA:
	case LISTITEM:
	default:
		break;
	};
}



void
sect_formalpara_start_element (Context *context, const gchar *name, const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<P>");
}

void
sect_formalpara_end_element (Context *context, const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</P>");
}


void
sect_sect_start_element (Context *context,
			const gchar *name,
			const xmlChar **atrs)
{
	gchar **atrs_ptr;
	SectContext *sect_context = (SectContext *)context->data;

	g_return_if_fail (strlen (name) >= 5);
	atrs_ptr = (gchar **) atrs;
	while (atrs_ptr && *atrs_ptr) {
		if (!g_strcasecmp (*atrs_ptr, "id")) {
			atrs_ptr++;
			((StackElement *)context->stack->data)->atrs = g_new0 (gchar *, 3);
			((StackElement *)context->stack->data)->atrs[0] = g_strdup ("id");
			((StackElement *)context->stack->data)->atrs[1] = g_strdup (*atrs_ptr);
			if (!strcmp (*atrs_ptr, context->target_section))
				sect_context->state = LOOKING_FOR_SECT_TITLE;
			break;
		}
		atrs_ptr += 2;
	}

	switch (name[4]) {
	case '1':
		if (sect_context->state != LOOKING_FOR_SECT_TITLE) {
			g_free (sect_context->prev);
			g_free (sect_context->previd);
		}
		context->sect1++;
		context->sect2 = 0;
		context->sect3 = 0;
		context->sect4 = 0;
		context->sect5 = 0;
		break;
	case '2':
		context->sect2++;
		context->sect3 = 0;
		context->sect4 = 0;
		context->sect5 = 0;
		break;
	case '3':
		context->sect3++;
		context->sect4 = 0;
		context->sect5 = 0;
		break;
	case '4':
		context->sect4++;
		break;
		context->sect5 = 0;
	case '5':
		context->sect4++;
		break;
	default:
		break;
	}
}

void
sect_sect_end_element (Context *context,
		      const gchar *name)
{
	gchar **atrs_ptr;

	g_return_if_fail (strlen (name) >= 5);

	switch (name[4]) {
	case '1':
		context->sect2 = 0;
	case '2':
		context->sect3 = 0;
	case '3':
		context->sect4 = 0;
	case '4':
		context->sect5 = 0;
	default:
		break;
	}
	atrs_ptr = ((StackElement *) context->stack->data)->atrs;

	while (atrs_ptr && *atrs_ptr) {
		if (!g_strcasecmp (*atrs_ptr, "id")) {
			atrs_ptr++;
			if (!strcmp (*atrs_ptr, context->target_section)) {
				((SectContext *)context->data)->state = LOOKING_FOR_POST_SECT;
			}
			break;
		}
		atrs_ptr += 2;
	}
}


void
sect_author_start_element (Context *context,
			  const gchar *name,
			  const xmlChar **atrs)
{
	GSList *element_list = NULL;
	AuthorInfo *author;
	ElementIndex index;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (ARTHEADER));
	index = find_first_parent (context, element_list);
	g_slist_free (element_list);

	switch (index) {
	case ARTHEADER:
		break;
	default:
		return;
	};
	author = g_new0 (AuthorInfo, 1);
	((SectContext *) context->data)->header->authors = g_slist_prepend (((SectContext *) context->data)->header->authors, author);
}

void
sect_author_characters (Context *context, const gchar *chars, int len)
{
	GSList *element_list = NULL;
	AuthorInfo *author;
	ElementIndex index;
	char *temp;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (ARTHEADER));
	index = find_first_parent (context, element_list);
	g_slist_free (element_list);

	switch (index) {
	case ARTHEADER:
		break;
	default:
		return;
	};

	author = (AuthorInfo *) ((SectContext *) context->data)->header->authors->data;
	g_return_if_fail (author != NULL);
	temp = g_strndup (chars, len);
	if (((StackElement *) context->stack->data)->info->index == FIRSTNAME)
		author->firstname = temp;
	else if (((StackElement *) context->stack->data)->info->index == OTHERNAME)
		author->othername = temp;
	else if (((StackElement *) context->stack->data)->info->index == SURNAME)
		author->surname = temp;
	else if (((StackElement *) context->stack->data)->info->index == EMAIL) {
		author->email = temp;
	} else if (((StackElement *) context->stack->data)->info->index == ORGNAME)
		author->orgname = temp;
	else
		g_free (temp);
}

void
sect_email_characters (Context *context, const gchar *chars, int len)
{
	GSList *element_list = NULL;
	ElementIndex index;
	char *temp;

	if (!IS_IN_SECT (context))
		return;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (ARTHEADER));
	index = find_first_parent (context, element_list);
	g_slist_free (element_list);

	switch (index) {
	case ARTHEADER:
		sect_author_characters (context, chars, len);
		return;
	default:
		break;
	};

	temp = g_strndup (chars, len);
	sect_print (context, "<tt>&lt;<A href=\"mailto:%s\">%s</A>&gt;</tt>", temp, temp);
	g_free (temp);
}

void
sect_copyright_characters (Context *context,
			  const gchar *chars,
			  int len)
{
	GSList *element_list = NULL;
	ElementIndex index;
	gchar *temp;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (COPYRIGHT));
	index = find_first_parent (context, element_list);
	g_slist_free (element_list);

	temp = g_strndup (chars, len);

	switch (index) {
	case COPYRIGHT:
		if (((StackElement *) context->stack->data)->info->index == YEAR)
			((SectContext *)context->data)->header->copyright_year = temp;
		else if (((StackElement *) context->stack->data)->info->index == HOLDER)
			((SectContext *)context->data)->header->copyright_holder = temp;
		break;
	default:
		g_free (temp);
		break;
	};
}

void
sect_title_start_element (Context *context,
			  const gchar *name,
			  const xmlChar **atrs)
{
	GSList *element_list = NULL;
	StackElement *stack_el;
	gchar **atrs_ptr;

	if (!IS_IN_SECT (context))
		return;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FIGURE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FORMALPARA));
	stack_el = find_first_element (context, element_list);

	g_slist_free (element_list);
	if (stack_el == NULL)
		return;


	switch (stack_el->info->index) {
	case SECT1:
	case SECT2:
	case SECT3:
	case SECT4:
	case SECT5:
	case SECTION:
		if (context->sect2 == 0)
			sect_print (context, "<H2>");
		else
			sect_print (context, "<H3>");
		sect_print (context, "<A name=\"");

		atrs_ptr = (stack_el->atrs);
		while (atrs_ptr && *atrs_ptr) {
			if (!g_strcasecmp (*atrs_ptr, "id")) {
				atrs_ptr++;
				sect_print (context, "%s", *atrs_ptr);
				break;
			}
			atrs_ptr += 2;
		}
		sect_print (context, "\">");
		break;
	case FORMALPARA:
		sect_print (context, "<B>");
		break;
	default:
		break;
	};

}

void
sect_title_end_element (Context *context,
			const gchar *name)
{
	GSList *element_list = NULL;
	ElementIndex index;

	if (!IS_IN_SECT (context))
		return;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FIGURE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FORMALPARA));

	index = find_first_parent (context, element_list);

	switch (index) {
	case SECT1:
	case SECTION:
		sect_print (context, "</A></H2>\n");
		break;
	case SECT2:
	case SECT3:
	case SECT4:
	case SECT5:
		sect_print (context, "</A></H3>\n");
		break;
	case FORMALPARA:
		sect_print (context, ".</B>");
		break;
	default:
		break;
	};

	g_slist_free (element_list);

}

void
sect_title_characters (Context *context,
		       const gchar *chars,
		       int len)
{
	GSList *element_list = NULL;
	ElementIndex index;
	char *temp;


	if (((SectContext *)context->data)->state == LOOKING_FOR_SECT_TITLE) {
		StackElement *stack_el;

		element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
		element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
		element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
		element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
		element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
		element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));

		stack_el = find_first_element (context, element_list);

		temp = g_strndup (chars, len);

		sect_print (context, "<TITLE>%s</TITLE>\n</HEAD>\n", temp);
		sect_print (context, "<BODY BGCOLOR=\"#FFFFFF\" TEXT=\"#000000\" LINK=\"#0000FF\" VLINK=\"#840084\" ALINK=\"#0000FF\">\n");
		if (stack_el == NULL)
			sect_print (context, "<A href=\"help:%s\"><font size=3>Up to Table of Contents</font></A><BR>\n",
				 context->base_file);
#if 0
		else
			sect_print (context, "<A href=\"help:%s#%s\"><font size=3>Up to %s</font></A><BR>\n",
				 context->base_file,
				 sect_context->topid,
				 sect_context->top);
#endif
		sect_print (context, "<H1>%s</H1>\n", temp);
		((SectContext *)context->data)->state = IN_SECT;
		g_free (temp);
		return;
	}

	if (!IS_IN_SECT (context))
		return;

	temp = g_strndup (chars, len);


	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (ARTHEADER));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FIGURE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FORMALPARA));

	index = find_first_parent (context, element_list);

	switch (index) {
	case SECT1:
	case SECT2:
	case SECT3:
	case SECT4:
	case SECT5:
	case SECTION:
	case FORMALPARA:
		sect_print (context, temp);
		g_free (temp);
		break;
	case ARTHEADER:
		if (((StackElement *)context->stack->data)->info->index == TITLE)
			((SectContext *) context->data)->header->title = temp;
		else if (((StackElement *)context->stack->data)->info->index == SUBTITLE)
			((SectContext *) context->data)->header->subtitle = temp;
		break;
	case FIGURE:
		((SectContext *) context->data)->figure->title = temp;
		break;
	default:
		g_free (temp);
		break;
	};

	g_slist_free (element_list);
}

void
sect_ulink_start_element (Context *context, const gchar *name, const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	ulink_start_element (context, name, atrs);
}


void
sect_ulink_end_element (Context *context, const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	ulink_end_element (context, name);
}

void
sect_link_start_element (Context *context,
			 const char *name,
			 const xmlChar **atrs)
{
	gchar **atrs_ptr;

	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<A HREF=\"help:%s", context->base_file);
	atrs_ptr = (gchar **) atrs;
	while (atrs_ptr && *atrs_ptr) {
		if (g_strcasecmp (*atrs_ptr, "linkend") == 0) {
			atrs_ptr++;
			sect_print (context, "?%s", *atrs_ptr);
			break;
		}
	}
	sect_print (context, "\">");
}

void
sect_link_end_element (Context *context, const char *name)
{
	if (!IS_IN_SECT (context))
		return;
	
	sect_print (context, "</A>");
}

void
sect_xref_start_element (Context *context,
			const gchar *name,
			const xmlChar **atrs)
{
	gchar **atrs_ptr;
	gchar *title = NULL;

	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<A HREF=\"help:%s", context->base_file);
	atrs_ptr = (gchar **) atrs;
	while (atrs_ptr && *atrs_ptr) {
		if (!g_strcasecmp (*atrs_ptr, "linkend")) {
			atrs_ptr++;
			sect_print (context, "?%s", *atrs_ptr);
			break;
		}
		atrs_ptr += 2;
	}

	if (*atrs_ptr)
		title = g_hash_table_lookup (((SectContext *)context->data)->title_hash, *atrs_ptr);

	if (title == NULL)
		sect_print (context, "\">the section here</A>");
	else
		sect_print (context, "\">the section <EM>%s</EM></A>", title);
}

void
sect_footnote_start_element (Context *context, const gchar *name, const xmlChar **atrs)
{
	GString *footnote;
	gint i;

	if (!IS_IN_SECT (context))
		return;

	footnote = g_string_new (NULL);
	context->footnotes = g_slist_append (context->footnotes, footnote);
	i = g_slist_length (context->footnotes);
	g_print ("<A NAME=\"HEADNOTE%d\" HREF=\"#FOOTNOTE%d\">[%d]</A>", i, i, i);
}

void
sect_figure_start_element (Context *context,
			    const gchar *name,
			    const xmlChar **atrs)
{
	SectContext *sect_context = (SectContext *)context->data;

	if (!IS_IN_SECT (context))
		return;

	if (sect_context->figure != NULL)
		return;

	sect_context->figure = g_new0 (FigureInfo, 1);
	sect_context->figure_count ++;
}

void
sect_figure_end_element (Context *context,
			  const gchar *name)
{
	SectContext *sect_context = (SectContext *)context->data;

	if (!IS_IN_SECT (context))
		return;

	if (sect_context->figure == NULL)
		return;

	if (sect_context->figure->img != NULL) {
 		if (sect_context->figure->id)
			sect_print (context, "<A NAME=\"%s\">",
				    sect_context->figure->id);
		sect_print (context, "<P><B>Figure %d.",
			    sect_context->figure_count);
 		if (sect_context->figure->title)
			sect_print (context, " %s",
				    sect_context->figure->title);
 		if (sect_context->figure->id)
			sect_print (context, "</A>");
		sect_print (context, "</B><P>");
		sect_print (context, "<IMG SRC=\"%s\" ALT=\"%s\"><P>",
			    sect_context->figure->img,
			    (sect_context->figure->alt) ? sect_context->figure->alt : "IMAGE");
	}
	g_free (sect_context->figure->title);
	g_free (sect_context->figure->alt);
	g_free (sect_context->figure->img);
	g_free (sect_context->figure->id);
	g_free (sect_context->figure);
	sect_context->figure = NULL;
}

void
sect_graphic_start_element (Context *context,
			    const gchar *name,
			    const xmlChar **atrs)
{
	gchar **atrs_ptr;
	gchar *format = NULL;
	gchar *fileref = NULL;
	gchar *lowcaseformat = NULL;
	SectContext *sect_context = (SectContext *)context->data;

	if (!IS_IN_SECT (context))
		return;

	atrs_ptr = (gchar **) atrs;
	while (atrs_ptr && *atrs_ptr) {
		if (!g_strcasecmp (*atrs_ptr, "format")) {
			atrs_ptr++;
			format =  *atrs_ptr;
			atrs_ptr++;
			continue;
		} else if (!g_strcasecmp (*atrs_ptr, "fileref")) {
			atrs_ptr++;
			fileref =  *atrs_ptr;
			atrs_ptr++;
			continue;
		} else if (!g_strcasecmp (*atrs_ptr, "id")) {
			atrs_ptr++;
			sect_context->figure->id = g_strdup (*atrs_ptr);
			atrs_ptr++;
			continue;
		}
		atrs_ptr += 2;
	}

	if (fileref == NULL)
		return;

	if (g_strcasecmp (format, "gif") == 0) {
		sect_context->figure->img = g_strdup_printf ("%s.gif", fileref);
	} else if ((g_strcasecmp (format, "jpg") == 0) ||
		   (g_strcasecmp (format, "jpeg") == 0)) {
		/* Some people decide to use .jpg, others use .jpeg */
		lowcaseformat = g_strdup (format);
		g_strdown (lowcaseformat);
		sect_context->figure->img = g_strdup_printf ("%s.%s", fileref, lowcaseformat);
		g_free (lowcaseformat);
	} else {
		sect_context->figure->img = g_strdup_printf ("%s.png", fileref);
	} 
}

void
sect_interface_start_element (Context *context,
				   const char *name,
				   const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<SPAN CLASS=\"INTERFACE\">");
}

void 
sect_interface_end_element (Context *context,
				 const char *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</SPAN>");
}

void
sect_em_start_element (Context *context,
		       const gchar *name,
		       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<EM>");
}

void
sect_em_end_element (Context *context,
		     const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</EM>");
}

void
sect_tt_start_element (Context *context,
		       const gchar *name,
		       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<TT>");
}

void
sect_tt_end_element (Context *context,
		     const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</TT>");
}

void 
sect_menu_start_element (Context *context,
			 const char *name,
			 const xmlChar **atrs)
{
	GSList *element_list = NULL;
	ElementIndex index;
	
	if (!IS_IN_SECT (context))
		return;
	
/*	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT1));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT2));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT3));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT4));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECT5));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (SECTION));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FIGURE));
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (FORMALPARA)); */
	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (MENUCHOICE));

	index = find_first_parent (context, element_list);
	g_slist_free (element_list);
	
	switch (index) {
		case MENUCHOICE:
			sect_print (context, "<B>");
			break;
		default:
			return;
	};
}

void
sect_menu_end_element (Context *context,
                         const char *name)
{
        GSList *element_list = NULL;
        ElementIndex index;

        if (!IS_IN_SECT (context))
                return;

	element_list = g_slist_prepend (element_list, GINT_TO_POINTER (MENUCHOICE));
        index = find_first_parent (context, element_list);
	g_slist_free (element_list);

        switch (index) {
                case MENUCHOICE:
                        sect_print (context, "-&gt;</B>");
                        break;
                default:
                        return;
        };
}


void
sect_b_start_element (Context *context,
		       const gchar *name,
		       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<B>");
}

void
sect_b_end_element (Context *context,
		     const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</B>");
}

void sect_b_arrow_end_element (Context *context,
                               const gchar *name)
{
	        if (!IS_IN_SECT (context))
			return;
		
		sect_print (context, "-&gt;</B>");
}

void
sect_tti_start_element (Context *context,
		       const gchar *name,
		       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<TT><I>");
}

void
sect_tti_end_element (Context *context,
		     const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</I></TT>");
}

void
sect_btt_start_element (Context *context,
		       const gchar *name,
		       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<B><TT>");
}

void
sect_btt_end_element (Context *context,
		     const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</TT></B>");
}

void
sect_i_start_element (Context *context,
		       const gchar *name,
		       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<I>");
}

void
sect_i_end_element (Context *context,
		     const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</I>");
}

void
sect_itemizedlist_start_element (Context *context,
				 const gchar *name,
				 const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<UL>");
}

void
sect_itemizedlist_end_element (Context *context,
			       const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</UL>");
}

void
sect_orderedlist_start_element (Context *context,
				 const gchar *name,
				 const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<OL>");
}

void
sect_orderedlist_end_element (Context *context,
			       const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</OL>");
}

void
sect_variablelist_start_element (Context *context,
				 const gchar *name,
				 const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<OL>");
}

void
sect_variablelist_end_element (Context *context,
			       const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</OL>");
}

void
sect_listitem_start_element (Context *context,
			     const gchar *name,
			     const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<LI>");
}

void
sect_listitem_end_element (Context *context,
			   const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<P>");
}

void
sect_programlisting_start_element (Context *context,
				   const gchar *name,
				   const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<table border=\"0\" bgcolor=\"#E0E0E0\" width=\"100%%\">\n<tr><td>\n<pre>");
}

void
sect_programlisting_end_element (Context *context,
				 const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</pre>\n</td></tr>\n</table>\n");
}

/* Note that this can return NULL if the file is not found */
static gchar *
sect_get_infobox_logo (const gchar *name)
{
	if (!g_strcasecmp (name, "tip"))
		return gnome_pixmap_file ("gnome-info.png");
	else if (!g_strcasecmp (name, "warning"))
		return gnome_pixmap_file ("gnome-warning.png");
	else if (!g_strcasecmp (name, "important"))
		return gnome_pixmap_file ("gnome-info.png");
	else if (!g_strcasecmp (name, "note"))
		return gnome_pixmap_file ("gnome-info.png");
	return gnome_pixmap_file ("gnome-info.png");
}

void
sect_infobox_start_element (Context *context,
			const gchar *name,
			const xmlChar **atrs)
{
	gchar *logo;

	if (!IS_IN_SECT (context))
		return;

	logo = sect_get_infobox_logo (name);

	sect_print (context, "<TABLE BORDER=\"0\"  WIDTH=\"100%%\">\n<tr><TD WIDTH=\"25%%\" ALIGN=\"CENTER\" VALIGN=\"TOP\">");
	if (logo != NULL)
		sect_print (context, "<IMG ALT=\"%s\" SRC=\"%s\">", name, logo);
	else
		sect_print (context, "%s", name);
	sect_print (context, "<TH ALIGN=\"LEFT\" VALIGN=\"CENTER\"></TD>\n");
	sect_print (context, "<TD>&nbsp;</TD>\n<TD ALIGN=\"LEFT\" VALIGN=\"TOP\">\n");
	g_free (logo);
}

void
sect_infobox_end_element (Context *context,
		      const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "</td></tr>\n</table>\n");
}

void
sect_cdata_characters (Context *context,
		      const gchar *chars,
		      int len)
{
	gint i;
	if (!IS_IN_SECT (context))
		return;

	for (i = 0; i < len; i++) {
		if ((i == 0) && (*chars == '\n'))
			continue;
		if (chars[i] == '<')
			sect_print (context, "&lt;");
		else sect_print (context, "%c", chars[i]);
	}

}

void
sect_keysym_start_element (Context *context,
			   const gchar *name,
			   const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "<B>(");
}

void
sect_keysym_end_element (Context *context, const gchar *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, ")</B>");
}

void
sect_funcsynopsis_start_element (Context        *context,
				 const gchar    *name,
				 const xmlChar **atrs)
{
}

void
sect_funcsynopsis_end_element (Context        *context,
			       const gchar    *name)
{
	GSList *list;
	GSList *list2;
	SectFuncProtoInfo *proto;

	if (!IS_IN_SECT (context))
		return;

	list = ((SectContext *) context->data)->func_synopsis;

	sect_print (context, "<TABLE BGCOLOR=\"#E0E0E0\" CELLSPACING=\"0\" CELLPADDING=\"0\" BORDER=\"0\">\n");
	while (list) {
		proto = (SectFuncProtoInfo *) list->data;
		if (proto == NULL)
			continue;

		sect_print (context, "<TR BGCOLOR=\"#E0E0E0\" >");
		if (proto->retval)
			sect_print (context, "<TD VALIGN=TOP BGCOLOR=\"#E0E0E0\">%s</TD>\n", proto->retval);
		else
			sect_print (context, "<TD VALIGN=TOP BGCOLOR=\"#E0E0E0\"></TD>\n");
		if (proto->func)
			sect_print (context, "<TD VALIGN=TOP BGCOLOR=\"#E0E0E0\">&nbsp;%s</TD><TD VALIGN=TOP BGCOLOR=\"#E0E0E0\">&nbsp;(</TD>\n", proto->func->str);
		else
			sect_print (context, "<TD VALIGN=TOP BGCOLOR=\"#E0E0E0\"></TD>\n");
		sect_print (context, "<TD VALIGN=TOP BGCOLOR=\"#E0E0E0\">\n");
		list2 = proto->params;
		if (list2 && list2->data) {
			sect_print (context, "%s", ((GString *)list2->data)->str);
			list2 = list2->next;
		}
		for (;list2; list2 = list2->next) {
			if (list2->data)
				sect_print (context, ",<BR>\n%s", ((GString *)list2->data)->str);
		}
		sect_print (context, ")</TD></TR>\n");
		list = list->next;
	}
	g_slist_free (((SectContext *) context->data)->func_synopsis);
	((SectContext *) context->data)->func_synopsis = NULL;
	sect_print (context, "</TABLE><BR>\n");
}

void
sect_funcprototype_start_element (Context        *context,
				  const gchar    *name,
				  const xmlChar **atrs)
{
	SectFuncProtoInfo *proto;

	if (!IS_IN_SECT (context))
		return;

	proto = g_new0 (SectFuncProtoInfo, 1);
	((SectContext *) context->data)->func_synopsis =
		g_slist_append (((SectContext *) context->data)->func_synopsis,
				proto);
}


void
sect_funcdef_characters (Context        *context,
			 const gchar    *chars,
			 int             len)
{
	SectFuncProtoInfo *proto;
	GSList *list;

	if (!IS_IN_SECT (context))
		return;

	if (((SectContext *) context->data)->func_synopsis == NULL)
		return;

	proto = g_new0 (SectFuncProtoInfo, 1);
	list = g_slist_last (((SectContext *) context->data)->func_synopsis);
	proto = (SectFuncProtoInfo *) list->data;
	if (proto->retval == NULL)
		proto->retval = g_strndup (chars, len);
}

void
sect_funcparams_start_element (Context        *context,
			       const gchar    *name,
			       const xmlChar **atrs)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "(");
}

void
sect_funcparams_end_element (Context        *context,
			     const gchar    *name)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, ")");
}

void
sect_paramdef_start_element (Context        *context,
			     const gchar    *chars,
			     int             len)
{
	SectFuncProtoInfo *proto;
	GSList *list;
	
	if (!IS_IN_SECT (context))
		return;

	if (((SectContext *) context->data)->func_synopsis == NULL)
		return;

	list = g_slist_last (((SectContext *)(context->data))->func_synopsis);

	proto = (SectFuncProtoInfo *) list->data;

	if (proto == NULL)
		return;

	proto->params = g_slist_append (proto->params, g_string_new (""));
}
void
sect_void_start_element (Context        *context,
			 const gchar    *chars,
			 int             len)
{
	if (!IS_IN_SECT (context))
		return;

	sect_print (context, "void");
}
