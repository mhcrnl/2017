/*
 * This file was generated by orbit-idl - DO NOT EDIT!
 */

#include <string.h>
#include "trilobite-eazel-time-service.h"

void
_ORBIT_Trilobite_Eazel_Time_NotPermitted_demarshal(GIOPRecvBuffer *
						   _ORBIT_recv_buffer,
						   CORBA_Environment * ev)
{
   CORBA_exception_set(ev, CORBA_USER_EXCEPTION,
		       TC_Trilobite_Eazel_Time_NotPermitted_struct.repo_id,
		       NULL);
}

void
_ORBIT_Trilobite_Eazel_Time_CannotSet_demarshal(GIOPRecvBuffer *
						_ORBIT_recv_buffer,
						CORBA_Environment * ev)
{
   CORBA_exception_set(ev, CORBA_USER_EXCEPTION,
		       TC_Trilobite_Eazel_Time_CannotSet_struct.repo_id,
		       NULL);
}

void
_ORBIT_Trilobite_Eazel_Time_CannotGetTime_demarshal(GIOPRecvBuffer *
						    _ORBIT_recv_buffer,
						    CORBA_Environment * ev)
{
   guchar *_ORBIT_curptr;
   register CORBA_unsigned_long _ORBIT_tmpvar_0;
   CORBA_unsigned_long _ORBIT_tmpvar_1;
   register CORBA_unsigned_long _ORBIT_tmpvar_2;
   CORBA_unsigned_long _ORBIT_tmpvar_3;
   Trilobite_Eazel_Time_CannotGetTime *_ORBIT_exdata =
      Trilobite_Eazel_Time_CannotGetTime__alloc();

   _ORBIT_curptr = GIOP_RECV_BUFFER(_ORBIT_recv_buffer)->cur;
   if (giop_msg_conversion_needed(GIOP_MESSAGE_BUFFER(_ORBIT_recv_buffer))) {
      _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
      
	 (*((guint32 *) & (_ORBIT_tmpvar_1))) =
	 GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr)); _ORBIT_curptr += 4;
      (*_ORBIT_exdata).url = CORBA_string_alloc(_ORBIT_tmpvar_1);
      memcpy((*_ORBIT_exdata).url, _ORBIT_curptr,
	     sizeof((*_ORBIT_exdata).url[_ORBIT_tmpvar_0]) * _ORBIT_tmpvar_1);
      _ORBIT_curptr +=
	 sizeof((*_ORBIT_exdata).url[_ORBIT_tmpvar_0]) * _ORBIT_tmpvar_1;
      _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
      
	 (*((guint32 *) & (_ORBIT_tmpvar_3))) =
	 GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr)); _ORBIT_curptr += 4;
      (*_ORBIT_exdata).reason = CORBA_string_alloc(_ORBIT_tmpvar_3);
      memcpy((*_ORBIT_exdata).reason, _ORBIT_curptr,
	     sizeof((*_ORBIT_exdata).reason[_ORBIT_tmpvar_2]) *
	     _ORBIT_tmpvar_3);
      _ORBIT_curptr +=
	 sizeof((*_ORBIT_exdata).reason[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
   } else {
      _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
      _ORBIT_tmpvar_1 = *((CORBA_unsigned_long *) _ORBIT_curptr);
      _ORBIT_curptr += 4;
      (*_ORBIT_exdata).url = CORBA_string_alloc(_ORBIT_tmpvar_1);
      memcpy((*_ORBIT_exdata).url, _ORBIT_curptr,
	     sizeof((*_ORBIT_exdata).url[_ORBIT_tmpvar_0]) * _ORBIT_tmpvar_1);
      _ORBIT_curptr +=
	 sizeof((*_ORBIT_exdata).url[_ORBIT_tmpvar_0]) * _ORBIT_tmpvar_1;
      _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
      _ORBIT_tmpvar_3 = *((CORBA_unsigned_long *) _ORBIT_curptr);
      _ORBIT_curptr += 4;
      (*_ORBIT_exdata).reason = CORBA_string_alloc(_ORBIT_tmpvar_3);
      memcpy((*_ORBIT_exdata).reason, _ORBIT_curptr,
	     sizeof((*_ORBIT_exdata).reason[_ORBIT_tmpvar_2]) *
	     _ORBIT_tmpvar_3);
      _ORBIT_curptr +=
	 sizeof((*_ORBIT_exdata).reason[_ORBIT_tmpvar_2]) * _ORBIT_tmpvar_3;
   }
   CORBA_exception_set(ev, CORBA_USER_EXCEPTION,
		       TC_Trilobite_Eazel_Time_CannotGetTime_struct.repo_id,
		       _ORBIT_exdata);
}

void
Trilobite_Eazel_Time_set_max_difference(Trilobite_Eazel_Time _obj,
					const CORBA_long maxd,
					CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Trilobite_Eazel_Time__classid) {
      
	 ((POA_Trilobite_Eazel_Time__epv *) _obj->
       vepv[Trilobite_Eazel_Time__classid])->set_max_difference(_obj->servant,
								maxd, ev);
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
	 char opname[19];
      }
      _ORBIT_operation_name_data =
      {
      19, "set_max_difference"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 23 };

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      giop_message_buffer_do_alignment(GIOP_MESSAGE_BUFFER
				       (_ORBIT_send_buffer), 4);
      giop_message_buffer_append_mem(GIOP_MESSAGE_BUFFER(_ORBIT_send_buffer),
				     &(maxd), sizeof(maxd));
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
Trilobite_Eazel_Time_set_time_url(Trilobite_Eazel_Time _obj,
				  const CORBA_char * url,
				  CORBA_Environment * ev)
{
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Trilobite_Eazel_Time__classid) {
      
	 ((POA_Trilobite_Eazel_Time__epv *) _obj->
       vepv[Trilobite_Eazel_Time__classid])->set_time_url(_obj->servant, url,
							  ev);
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
	 char opname[13];
      }
      _ORBIT_operation_name_data =
      {
      13, "set_time_url"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 17 };
      register CORBA_unsigned_long _ORBIT_tmpvar_0;
      CORBA_unsigned_long _ORBIT_tmpvar_1;

      _ORBIT_send_buffer =
	 giop_send_request_buffer_use(_cnx, NULL, _ORBIT_request_id,
				      CORBA_TRUE,
				      &(_obj->active_profile->object_key_vec),
				      &_ORBIT_operation_vec,
				      &ORBit_default_principal_iovec);

      _ORBIT_system_exception_minor = ex_CORBA_COMM_FAILURE;
      if (!_ORBIT_send_buffer)
	 goto _ORBIT_system_exception;
      _ORBIT_tmpvar_1 = strlen(url) + 1;
      giop_message_buffer_do_alignment(GIOP_MESSAGE_BUFFER
				       (_ORBIT_send_buffer), 4);
      {
	 guchar *_ORBIT_t;

	 _ORBIT_t = alloca(sizeof(_ORBIT_tmpvar_1));
	 memcpy(_ORBIT_t, &(_ORBIT_tmpvar_1), sizeof(_ORBIT_tmpvar_1));
	 giop_message_buffer_append_mem(GIOP_MESSAGE_BUFFER
					(_ORBIT_send_buffer), (_ORBIT_t),
					sizeof(_ORBIT_tmpvar_1));
      }
      giop_message_buffer_append_mem(GIOP_MESSAGE_BUFFER(_ORBIT_send_buffer),
				     (url),
				     sizeof(url[_ORBIT_tmpvar_0]) *
				     _ORBIT_tmpvar_1);
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
CORBA_unsigned_long
Trilobite_Eazel_Time_check_time(Trilobite_Eazel_Time _obj,
				CORBA_Environment * ev)
{
   static const ORBit_exception_demarshal_info _ORBIT_user_exceptions[] =
      { {(const CORBA_TypeCode) &TC_Trilobite_Eazel_Time_CannotGetTime_struct,
	 (gpointer) _ORBIT_Trilobite_Eazel_Time_CannotGetTime_demarshal},
      {CORBA_OBJECT_NIL, NULL} };
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;
   CORBA_unsigned_long _ORBIT_retval;

   if (_obj->servant && _obj->vepv && Trilobite_Eazel_Time__classid) {
      _ORBIT_retval =
	 ((POA_Trilobite_Eazel_Time__epv *) _obj->
	  vepv[Trilobite_Eazel_Time__classid])->check_time(_obj->servant, ev);
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
	 char opname[11];
      }
      _ORBIT_operation_name_data =
      {
      11, "check_time"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 15 };

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
	 
	    (*((guint32 *) & (_ORBIT_retval))) =
	    GUINT32_SWAP_LE_BE(*((guint32 *) _ORBIT_curptr));} else {
	 _ORBIT_curptr = ALIGN_ADDRESS(_ORBIT_curptr, 4);
	 _ORBIT_retval = *((CORBA_unsigned_long *) _ORBIT_curptr);
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
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev,
				_ORBIT_user_exceptions, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return _ORBIT_retval;
      }
   }
}
void
Trilobite_Eazel_Time_update_time(Trilobite_Eazel_Time _obj,
				 CORBA_Environment * ev)
{
   static const ORBit_exception_demarshal_info _ORBIT_user_exceptions[] =
      { {(const CORBA_TypeCode) &TC_Trilobite_Eazel_Time_NotPermitted_struct,
	 (gpointer) _ORBIT_Trilobite_Eazel_Time_NotPermitted_demarshal},
      {(const CORBA_TypeCode) &TC_Trilobite_Eazel_Time_CannotGetTime_struct,
       (gpointer) _ORBIT_Trilobite_Eazel_Time_CannotGetTime_demarshal},
      {CORBA_OBJECT_NIL, NULL} };
   register GIOP_unsigned_long _ORBIT_request_id,
    _ORBIT_system_exception_minor;
   register CORBA_completion_status _ORBIT_completion_status;
   register GIOPSendBuffer *_ORBIT_send_buffer;
   register GIOPRecvBuffer *_ORBIT_recv_buffer;
   register GIOPConnection *_cnx;

   if (_obj->servant && _obj->vepv && Trilobite_Eazel_Time__classid) {
      
	 ((POA_Trilobite_Eazel_Time__epv *) _obj->
       vepv[Trilobite_Eazel_Time__classid])->update_time(_obj->servant, ev);
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
	 char opname[12];
      }
      _ORBIT_operation_name_data =
      {
      12, "update_time"};
      static const struct iovec _ORBIT_operation_vec =
	 { (gpointer) & _ORBIT_operation_name_data, 16 };

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
	 ORBit_handle_exception(_ORBIT_recv_buffer, ev,
				_ORBIT_user_exceptions, _obj->orb);
	 giop_recv_buffer_unuse(_ORBIT_recv_buffer);
	 return;
      }
   }
}