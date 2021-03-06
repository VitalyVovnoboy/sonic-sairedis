#include "sai_vs.h"

sai_status_t vs_create_samplepacket_session(
        _Out_ sai_object_id_t *session_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    std::lock_guard<std::recursive_mutex> lock(g_recursive_mutex);

    SWSS_LOG_ENTER();

    return meta_sai_create_oid(
            SAI_OBJECT_TYPE_SAMPLEPACKET,
            session_id,
            attr_count,
            attr_list,
            &vs_generic_create);
}

sai_status_t vs_remove_samplepacket_session(
        _In_ sai_object_id_t session_id)
{
    std::lock_guard<std::recursive_mutex> lock(g_recursive_mutex);

    SWSS_LOG_ENTER();

    return meta_sai_remove_oid(
            SAI_OBJECT_TYPE_SAMPLEPACKET,
            session_id,
            &vs_generic_remove);
}

sai_status_t vs_set_samplepacket_attribute(
        _In_ sai_object_id_t session_id,
        _In_ const sai_attribute_t *attr)
{
    std::lock_guard<std::recursive_mutex> lock(g_recursive_mutex);

    SWSS_LOG_ENTER();

    return meta_sai_set_oid(
            SAI_OBJECT_TYPE_SAMPLEPACKET,
            session_id,
            attr,
            &vs_generic_set);
}

sai_status_t vs_get_samplepacket_attribute(
        _In_ sai_object_id_t session_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    std::lock_guard<std::recursive_mutex> lock(g_recursive_mutex);

    SWSS_LOG_ENTER();

    return meta_sai_get_oid(
            SAI_OBJECT_TYPE_SAMPLEPACKET,
            session_id,
            attr_count,
            attr_list,
            &vs_generic_get);
}

const sai_samplepacket_api_t vs_samplepacket_api = {
    vs_create_samplepacket_session,
    vs_remove_samplepacket_session,
    vs_set_samplepacket_attribute,
    vs_get_samplepacket_attribute,
};
