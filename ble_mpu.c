 /* 
  * This code is not extensively tested and only 
  * meant as a simple explanation and for inspiration. 
  * NO WARRANTY of ANY KIND is provided. 
  */

#include <stdint.h>
#include <string.h>
#include "nrf_gpio.h"
#include "ble_mpu.h"
#include "ble_srv_common.h"
#include "app_error.h"
/**@Needed for 'updates'*/
#if (defined(MPU60x0) || defined(MPU9150) || defined(MPU9255))
#include "mpu.h"
#endif /**@(defined(MPU60x0) || defined(MPU9150) || defined(MPU9255))*/




void ble_mpu_on_ble_evt(ble_mpu_t * p_mpu, ble_evt_t * p_ble_evt)
{
    switch (p_ble_evt->header.evt_id)
    {
        case BLE_GAP_EVT_CONNECTED:
            p_mpu->conn_handle = p_ble_evt->evt.gap_evt.conn_handle;
            break;
        case BLE_GAP_EVT_DISCONNECTED:
            p_mpu->conn_handle = BLE_CONN_HANDLE_INVALID;
        default:
            // No implementation needed.
            break;
    }
}

/**@brief Function for adding our new characterstic to "Our service" that we initiated in the previous tutorial. 
 *
 * @param[in]   p_mpu        mpu structure.
 *
 
static uint32_t ble_char_accel_add(ble_mpu_t * p_mpu)
{
    uint32_t   err_code = 0; // Variable to hold return codes from library and softdevice functions
    
    ble_uuid_t          char_uuid;   
    BLE_UUID_BLE_ASSIGN(char_uuid, BLE_UUID_ACCEL_CHARACTERISTC_UUID);
	
    ble_gatts_char_md_t char_md;
    memset(&char_md, 0, sizeof(char_md));
    char_md.char_props.read = 1;
    char_md.char_props.write = 0;
    
    ble_gatts_attr_md_t cccd_md;
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.write_perm);
    cccd_md.vloc                = BLE_GATTS_VLOC_STACK;    
    char_md.p_cccd_md           = &cccd_md;
    char_md.char_props.notify   = 1;
        
    ble_gatts_attr_md_t attr_md;
    memset(&attr_md, 0, sizeof(attr_md));
    attr_md.vloc = BLE_GATTS_VLOC_STACK;    
    
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.write_perm);
    
    ble_gatts_attr_t    attr_char_value;
    memset(&attr_char_value, 0, sizeof(attr_char_value));
    attr_char_value.p_uuid      = &char_uuid;
    attr_char_value.p_attr_md   = &attr_md;
    attr_char_value.max_len     = sizeof(accel_values_t);
    attr_char_value.init_len    = sizeof(accel_values_t);
    uint8_t value[6]           = {0};
    attr_char_value.p_value     = value;
    err_code = sd_ble_gatts_characteristic_add(p_mpu->service_handle,
                                       &char_md,
                                       &attr_char_value,
                                       &p_mpu->accel_char_handles);
    APP_ERROR_CHECK(err_code);   

    return NRF_SUCCESS;
}*/

/**@brief Function for adding gyro characterstic to "MPUservice" that we initiated in the previous tutorial. 
 *
 * @param[in]   p_mpu        mpu structure.
 *
 
static uint32_t ble_char_gyro_add(ble_mpu_t * p_mpu) {
		uint32_t   err_code = 0; // Variable to hold return codes from library and softdevice functions
    
    ble_uuid_t          char_uuid;   
    BLE_UUID_BLE_ASSIGN(char_uuid, BLE_UUID_GYROS_CHARACTERISTC_UUID);
	
    ble_gatts_char_md_t char_md;
    memset(&char_md, 0, sizeof(char_md));
    char_md.char_props.read = 1;
    char_md.char_props.write = 0;
    
    ble_gatts_attr_md_t cccd_md;
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.write_perm);
    cccd_md.vloc                = BLE_GATTS_VLOC_STACK;    
    char_md.p_cccd_md           = &cccd_md;
    char_md.char_props.notify   = 1;
        
    ble_gatts_attr_md_t attr_md;
    memset(&attr_md, 0, sizeof(attr_md));
    attr_md.vloc = BLE_GATTS_VLOC_STACK;    
    
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.write_perm);
    
    ble_gatts_attr_t    attr_char_value;
    memset(&attr_char_value, 0, sizeof(attr_char_value));
    attr_char_value.p_uuid      = &char_uuid;
    attr_char_value.p_attr_md   = &attr_md;
    attr_char_value.max_len     = sizeof(gyro_values_t);
    attr_char_value.init_len    = sizeof(gyro_values_t);
    uint8_t value[6]            = {0};
    attr_char_value.p_value     = value;

    err_code = sd_ble_gatts_characteristic_add(p_mpu->service_handle,
                                       &char_md,
                                       &attr_char_value,
                                       &p_mpu->gyro_char_handles);
    APP_ERROR_CHECK(err_code);   

    return NRF_SUCCESS;
}
*/
/**@brief Function for adding temperature characterstic to "MPUservice" that we initiated in the previous tutorial. 
 *
 * @param[in]   p_mpu        mpu structure.
 *
 
static uint32_t ble_char_temp_add(ble_mpu_t * p_mpu) {
		uint32_t   err_code = 0; // Variable to hold return codes from library and softdevice functions
    
    ble_uuid_t          char_uuid;   
    BLE_UUID_BLE_ASSIGN(char_uuid, BLE_UUID_TEMP_CHARACTERISTC_UUID);
	
    ble_gatts_char_md_t char_md;
    memset(&char_md, 0, sizeof(char_md));
    char_md.char_props.read = 1;
    char_md.char_props.write = 0;
    
    ble_gatts_attr_md_t cccd_md;
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.write_perm);
    cccd_md.vloc                = BLE_GATTS_VLOC_STACK;    
    char_md.p_cccd_md           = &cccd_md;
    char_md.char_props.notify   = 1;
        
    ble_gatts_attr_md_t attr_md;
    memset(&attr_md, 0, sizeof(attr_md));
    attr_md.vloc = BLE_GATTS_VLOC_STACK;    
    
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.write_perm);
    
    ble_gatts_attr_t    attr_char_value;
    memset(&attr_char_value, 0, sizeof(attr_char_value));
    attr_char_value.p_uuid      = &char_uuid;
    attr_char_value.p_attr_md   = &attr_md;
    attr_char_value.max_len     = sizeof(temp_value_t);
    attr_char_value.init_len    = sizeof(temp_value_t);
    uint8_t value[6]            = {0};
    attr_char_value.p_value     = value;

    err_code = sd_ble_gatts_characteristic_add(p_mpu->service_handle,
                                       &char_md,
                                       &attr_char_value,
                                       &p_mpu->temp_char_handles);
    APP_ERROR_CHECK(err_code);   

    return NRF_SUCCESS;
}
*/
/**@brief Function for adding magntometer characterstic to "MPUservice" that we initiated in the previous tutorial. 
 *
 * @param[in]   p_mpu        mpu structure.
 *
 
static uint32_t ble_char_magn_add(ble_mpu_t * p_mpu) {
		uint32_t   err_code = 0; // Variable to hold return codes from library and softdevice functions
    
    ble_uuid_t          char_uuid;   
    BLE_UUID_BLE_ASSIGN(char_uuid, BLE_UUID_MAGN_CHARACTERISTC_UUID);
	
    ble_gatts_char_md_t char_md;
    memset(&char_md, 0, sizeof(char_md));
    char_md.char_props.read = 1;
    char_md.char_props.write = 0;
    
    ble_gatts_attr_md_t cccd_md;
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.write_perm);
    cccd_md.vloc                = BLE_GATTS_VLOC_STACK;    
    char_md.p_cccd_md           = &cccd_md;
    char_md.char_props.notify   = 1;
        
    ble_gatts_attr_md_t attr_md;
    memset(&attr_md, 0, sizeof(attr_md));
    attr_md.vloc = BLE_GATTS_VLOC_STACK;    
    
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.write_perm);
    
    ble_gatts_attr_t    attr_char_value;
    memset(&attr_char_value, 0, sizeof(attr_char_value));
    attr_char_value.p_uuid      = &char_uuid;
    attr_char_value.p_attr_md   = &attr_md;
    attr_char_value.max_len     = sizeof(magn_values_t);
    attr_char_value.init_len    = sizeof(magn_values_t);
    uint8_t value[6]            = {0};
    attr_char_value.p_value     = value;

    err_code = sd_ble_gatts_characteristic_add(p_mpu->service_handle,
                                       &char_md,
                                       &attr_char_value,
                                       &p_mpu->magnt_char_handles);
    APP_ERROR_CHECK(err_code);   

    return NRF_SUCCESS;
}
*/
static uint32_t ble_char_combined_add(ble_mpu_t *p_mpu) {
		uint32_t   err_code = 0; // Variable to hold return codes from library and softdevice functions
    
    ble_uuid_t          char_uuid;   
		BLE_UUID_BLE_ASSIGN(char_uuid, BLE_UUID_COMBINED_CHARACTERISTC_UUID);
		ble_gatts_char_md_t char_md;
    memset(&char_md, 0, sizeof(char_md));
    char_md.char_props.read = 1;
    char_md.char_props.write = 0;
    
    ble_gatts_attr_md_t cccd_md;
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&cccd_md.write_perm);
    cccd_md.vloc                = BLE_GATTS_VLOC_STACK;    
    char_md.p_cccd_md           = &cccd_md;
    char_md.char_props.notify   = 1;
        
    ble_gatts_attr_md_t attr_md;
    memset(&attr_md, 0, sizeof(attr_md));
    attr_md.vloc = BLE_GATTS_VLOC_STACK;    
    
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.read_perm);
    BLE_GAP_CONN_SEC_MODE_SET_OPEN(&attr_md.write_perm);
    
    ble_gatts_attr_t    attr_char_value;
    memset(&attr_char_value, 0, sizeof(attr_char_value));
    attr_char_value.p_uuid      = &char_uuid;
    attr_char_value.p_attr_md   = &attr_md;
    attr_char_value.max_len     = sizeof(combined_values_t);
    attr_char_value.init_len    = sizeof(combined_values_t);
    uint8_t value[12]           = {0};
    attr_char_value.p_value     = value;
    err_code = sd_ble_gatts_characteristic_add(p_mpu->service_handle,
                                       &char_md,
                                       &attr_char_value,
                                       &p_mpu->combined_char_handles);
    APP_ERROR_CHECK(err_code);   

    return NRF_SUCCESS;
}

/**@brief Function for initiating our new service.
 *
 * @param[in]   p_mpu        Our Service structure.
 *
 */
void ble_mpu_service_init(ble_mpu_t * p_mpu)
{
    uint32_t   err_code; // Variable to hold return codes from library and softdevice functions

    ble_uuid_t        service_uuid;
    ble_uuid128_t     base_uuid = BLE_UUID_BASE_UUID;
    service_uuid.uuid = BLE_UUID_MPU_SERVICE_UUID;
    err_code = sd_ble_uuid_vs_add(&base_uuid, &service_uuid.type);
    APP_ERROR_CHECK(err_code);    

    p_mpu->conn_handle = BLE_CONN_HANDLE_INVALID;

    err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY,
                                        &service_uuid,
                                        &p_mpu->service_handle);
    
    APP_ERROR_CHECK(err_code);
    
    //ble_char_accel_add(p_mpu);
		//ble_char_gyro_add(p_mpu);
		//ble_char_magn_add(p_mpu);
		//ble_char_temp_add(p_mpu);
		ble_char_combined_add(p_mpu);
}
#if (defined(MPU60x0) || defined(MPU9150) || defined(MPU9255))

void ble_mpu_combined_update(ble_mpu_t *p_mpu, combined_values_t *combined_values){
		if (p_mpu->conn_handle != BLE_CONN_HANDLE_INVALID)
    {
        uint16_t               len = sizeof(combined_values_t);
        ble_gatts_hvx_params_t hvx_params;
        memset(&hvx_params, 0, sizeof(hvx_params));

        hvx_params.handle = p_mpu->combined_char_handles.value_handle;
        hvx_params.type   = BLE_GATT_HVX_NOTIFICATION;
        hvx_params.offset = 0;
        hvx_params.p_len  = &len;
				hvx_params.p_data = (uint8_t*)combined_values;
			//^Converted to 8-bit values
        sd_ble_gatts_hvx(p_mpu->conn_handle, &hvx_params);
    } 
}


// Function to be called when updating ACCEL characteristic value
void ble_mpu_accel_update(ble_mpu_t *p_mpu, accel_values_t * accel_values)
{	
    // Send value if connected and notifying
    if (p_mpu->conn_handle != BLE_CONN_HANDLE_INVALID)
    {
        uint16_t               len = sizeof(accel_values_t);
        ble_gatts_hvx_params_t hvx_params;
        memset(&hvx_params, 0, sizeof(hvx_params));

        hvx_params.handle = p_mpu->accel_char_handles.value_handle;
        hvx_params.type   = BLE_GATT_HVX_NOTIFICATION;
        hvx_params.offset = 0;
        hvx_params.p_len  = &len;
				hvx_params.p_data = (uint8_t*)accel_values;
			//^Converted to 8-bit values
        sd_ble_gatts_hvx(p_mpu->conn_handle, &hvx_params);
				//nrf_gpio_pin_toggle(22);
    } 
}

void ble_mpu_gyro_update(ble_mpu_t *p_mpu, gyro_values_t *gyro_values) {
		//Send if connected and notifying:
	
		if (p_mpu->conn_handle != BLE_CONN_HANDLE_INVALID){
				uint16_t										len = sizeof(gyro_values_t);
				ble_gatts_hvx_params_t			hvx_params;
				memset(&hvx_params, 0, sizeof(hvx_params));
				//IMPORTANT LINE:					 ?								?
				hvx_params.handle = p_mpu->gyro_char_handles.value_handle;
				hvx_params.type		= BLE_GATT_HVX_NOTIFICATION;
				hvx_params.offset = 0;
				hvx_params.p_len  = &len;
				hvx_params.p_data	= (uint8_t*)gyro_values;
				sd_ble_gatts_hvx(p_mpu->conn_handle, &hvx_params);
		}
}

void ble_mpu_magnt_update(ble_mpu_t *p_mpu, magn_values_t *magn_values) {
		if (p_mpu->conn_handle != BLE_CONN_HANDLE_INVALID){
				uint16_t										len = sizeof(magn_values_t);
				ble_gatts_hvx_params_t			hvx_params;
				memset(&hvx_params, 0, sizeof(hvx_params));
				hvx_params.handle = p_mpu->magnt_char_handles.value_handle;
				hvx_params.type		= BLE_GATT_HVX_NOTIFICATION;
				hvx_params.offset = 0;
				hvx_params.p_len  = &len;
				hvx_params.p_data	= (uint8_t*)magn_values;
				sd_ble_gatts_hvx(p_mpu->conn_handle, &hvx_params);
		}
}

void ble_mpu_temp_update(ble_mpu_t *p_mpu, temp_value_t *temperature) {
		if (p_mpu->conn_handle != BLE_CONN_HANDLE_INVALID){
				uint16_t										len = sizeof(temp_value_t);
				ble_gatts_hvx_params_t			hvx_params;
				memset(&hvx_params, 0, sizeof(hvx_params));
				hvx_params.handle = p_mpu->temp_char_handles.value_handle;
				hvx_params.type		= BLE_GATT_HVX_NOTIFICATION;
				hvx_params.offset = 0;
				hvx_params.p_len  = &len;
				hvx_params.p_data	= (uint8_t*)temperature;
				sd_ble_gatts_hvx(p_mpu->conn_handle, &hvx_params);
		}
}
#endif /**@(defined(MPU60x0) || defined(MPU9150) || defined(MPU9255))*/