/*
 * This file was generated by orbit-idl - DO NOT EDIT!
 */

#include <string.h>
#include "nautilus-distributed-undo.h"

Nautilus_Undo_MenuItem *
Nautilus_Undo_Transaction__get_undo_menu_item(Nautilus_Undo_Transaction _obj,
					      CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   Nautilus_Undo_MenuItem *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_4;
   CORBA_unsigned_long _ORBIT_tmpvar_5;
   register CORBA_unsigned_long _ORBIT_tmpvar_6;
   CORBA_unsigned_long _ORBIT_tmpvar_7;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Transaction__classid) {
      _ORBIT_retval =
	 ((POA_Nautilus_Undo_Transaction__epv *) _obj->
	  vepv[Nautilus_Undo_Transaction__classid])->
	 _get_undo_menu_item(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[20];
      }
      _ORBIT_operation_name_data =
      {
      20, "_get_undo_menu_item"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 24 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_retval = Nautilus_Undo_MenuItem__alloc();
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_5))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).label = CORBA_string_alloc(_ORBIT_tmpvar_5);
	 memcpy((*_ORBIT_retval).label, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) *
		_ORBIT_tmpvar_5);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5;
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_7))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).hint = CORBA_string_alloc(_ORBIT_tmpvar_7);
	 memcpy((*_ORBIT_retval).hint, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) *
		_ORBIT_tmpvar_7);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) * _ORBIT_tmpvar_7;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_5 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).label = CORBA_string_alloc(_ORBIT_tmpvar_5);
	 memcpy((*_ORBIT_retval).label, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) *
		_ORBIT_tmpvar_5);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5;
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_7 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).hint = CORBA_string_alloc(_ORBIT_tmpvar_7);
	 memcpy((*_ORBIT_retval).hint, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) *
		_ORBIT_tmpvar_7);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) * _ORBIT_tmpvar_7;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
Nautilus_Undo_MenuItem *
Nautilus_Undo_Transaction__get_redo_menu_item(Nautilus_Undo_Transaction _obj,
					      CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   Nautilus_Undo_MenuItem *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_4;
   CORBA_unsigned_long _ORBIT_tmpvar_5;
   register CORBA_unsigned_long _ORBIT_tmpvar_6;
   CORBA_unsigned_long _ORBIT_tmpvar_7;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Transaction__classid) {
      _ORBIT_retval =
	 ((POA_Nautilus_Undo_Transaction__epv *) _obj->
	  vepv[Nautilus_Undo_Transaction__classid])->
	 _get_redo_menu_item(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[20];
      }
      _ORBIT_operation_name_data =
      {
      20, "_get_redo_menu_item"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 24 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_retval = Nautilus_Undo_MenuItem__alloc();
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_5))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).label = CORBA_string_alloc(_ORBIT_tmpvar_5);
	 memcpy((*_ORBIT_retval).label, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) *
		_ORBIT_tmpvar_5);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5;
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_7))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).hint = CORBA_string_alloc(_ORBIT_tmpvar_7);
	 memcpy((*_ORBIT_retval).hint, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) *
		_ORBIT_tmpvar_7);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) * _ORBIT_tmpvar_7;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_5 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).label = CORBA_string_alloc(_ORBIT_tmpvar_5);
	 memcpy((*_ORBIT_retval).label, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) *
		_ORBIT_tmpvar_5);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).label[_ORBIT_tmpvar_4]) * _ORBIT_tmpvar_5;
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_7 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 (*_ORBIT_retval).hint = CORBA_string_alloc(_ORBIT_tmpvar_7);
	 memcpy((*_ORBIT_retval).hint, _ORBIT_curptr,
		sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) *
		_ORBIT_tmpvar_7);
	 _ORBIT_curptr +=
	    sizeof((*_ORBIT_retval).hint[_ORBIT_tmpvar_6]) * _ORBIT_tmpvar_7;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
CORBA_char *
Nautilus_Undo_Transaction__get_operation_name(Nautilus_Undo_Transaction _obj,
					      CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_char *_ORBIT_retval;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Transaction__classid) {
      _ORBIT_retval =
	 ((POA_Nautilus_Undo_Transaction__epv *) _obj->
	  vepv[Nautilus_Undo_Transaction__classid])->
	 _get_operation_name(_obj->servant, ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[20];
      }
      _ORBIT_operation_name_data =
      {
      20, "_get_operation_name"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 24 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 
	    (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      } else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
	 _ORBIT_curptr += 4;
	 _ORBIT_retval = CORBA_string_alloc(_ORBIT_tmpvar_3);
	 memcpy(_ORBIT_retval, _ORBIT_curptr,
		sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3);
	 _ORBIT_curptr +=
	    sizeof(_ORBIT_retval[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
void
Nautilus_Undo_Transaction_undo(Nautilus_Undo_Transaction _obj,
			       CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Transaction__classid) {
      
	 ((POA_Nautilus_Undo_Transaction__epv *) _obj->
       vepv[Nautilus_Undo_Transaction__classid])->undo(_obj->servant, ev);
      return;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[5];
      }
      _ORBIT_operation_name_data =
      {
      5, "undo"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 9 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
      } else {
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return;
      }
   }
}
void
Nautilus_Undo_Manager_append(Nautilus_Undo_Manager _obj,
			     const Nautilus_Undo_Transaction transaction,
			     CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Manager__classid) {
      
	 ((POA_Nautilus_Undo_Manager__epv *) _obj->
       vepv[Nautilus_Undo_Manager__classid])->append(_obj->servant,
						     transaction, ev);
      return;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[7];
      }
      _ORBIT_operation_name_data =
      {
      7, "append"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 11 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      ORBit_marshal_object(_ORBIT_send_buffer, transaction);
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
      } else {
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return;
      }
   }
}
void
Nautilus_Undo_Manager_forget(Nautilus_Undo_Manager _obj,
			     const Nautilus_Undo_Transaction transaction,
			     CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Manager__classid) {
      
	 ((POA_Nautilus_Undo_Manager__epv *) _obj->
       vepv[Nautilus_Undo_Manager__classid])->forget(_obj->servant,
						     transaction, ev);
      return;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[7];
      }
      _ORBIT_operation_name_data =
      {
      7, "forget"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 11 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      ORBit_marshal_object(_ORBIT_send_buffer, transaction);
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
      } else {
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return;
      }
   }
}
void
Nautilus_Undo_Manager_undo(Nautilus_Undo_Manager _obj, CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Manager__classid) {
      
	 ((POA_Nautilus_Undo_Manager__epv *) _obj->
       vepv[Nautilus_Undo_Manager__classid])->undo(_obj->servant, ev);
      return;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[5];
      }
      _ORBIT_operation_name_data =
      {
      5, "undo"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 9 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
      } else {
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return;
      }
   }
}
Nautilus_Undo_Manager
Nautilus_Undo_Context__get_undo_manager(Nautilus_Undo_Context _obj,
					CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   Nautilus_Undo_Manager _ORBIT_retval;

   if (_obj->servant && _obj->vepv && Nautilus_Undo_Context__classid) {
      _ORBIT_retval =
	 ((POA_Nautilus_Undo_Context__epv *) _obj->
	  vepv[Nautilus_Undo_Context__classid])->_get_undo_manager(_obj->
								   servant,
								   ev);
      return _ORBIT_retval;
   }
   _cnx = ORBit_object_get_connection(_obj);
 _ORBIT_retry_request:
   _ORBIT_send_buffer = NULL;
   _ORBIT_recv_buffer = NULL;
   _ORBIT_completion_status = CORBA_COMPLETED_NO;
   _ORBIT_request_id = GPOINTER_TO_UINT(alloca(0));
   {				/* marshalling */
      static const struct
      {
	 CORBA_unsigned_long len;
	 char opname[18];
      }
      _ORBIT_operation_name_data =
      {
      18, "_get_undo_manager"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 22 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_send_buffer_write(_ORBIT_send_buffer);
      _ORBIT_completion_status = CORBA_COMPLETED_MAYBE;
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      _ORBIT_send_buffer = NULL;
   }
   {				/* demarshalling */
      register guchar *_ORBIT_curptr;

      _ORBIT_recv_buffer =
	 giop_recv_reply_buffer_use_2(_cnx, _ORBIT_request_id, TRUE);
      if (!_ORBIT_recv_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_completion_status = CORBA_COMPLETED_YES;
      if (_ORBIT_recv_buffer->message.u.reply.reply_status !=
	  GIOP_NO_EXCEPTION) goto _ORBIT_msg_exception;
      _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
	 GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur = _ORBIT_curptr;
	 _ORBIT_retval =
	    ORBit_demarshal_object(_ORBIT_recv_buffer,
				   GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer)->
				   connection->orb_data);
	 _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      } else {
	 GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur = _ORBIT_curptr;
	 _ORBIT_retval =
	    ORBit_demarshal_object(_ORBIT_recv_buffer,
				   GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer)->
				   connection->orb_data);
	 _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
      }
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      return _ORBIT_retval;
    _ORBIT_system_exception:
      CORBA_exception_set_system(ev, _ORBIT_system_exception_minor,
				 _ORBIT_completion_status);
      giop_recv_buffer_unuse(_ORBIT_recv_buffer);
      giop_send_buffer_unuse(_ORBIT_send_buffer);
      return _ORBIT_retval;
    _ORBIT_msg_exception:
      if (_ORBIT_recv_buffer->message.u.reply.reply_status ==
	  GIOP_LOCATION_FORWARD) {
	 if (_obj->forward_locations != NULL)
	    ORBit_delete_profiles(_obj->forward_locations);
	 _obj->forward_locations = ORBit_demarshal_IOR(_ORBIT_recv_buffer);
	 _cnx = ORBit_object_get_forwarded_connection(_obj);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);

	 goto _ORBIT_retry_request;
      } else {
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev, NULL, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}