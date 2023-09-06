#ifndef TURTLEBOT3_NODE__CONTROL_TABLE_HPP_
#define TURTLEBOT3_NODE__CONTROL_TABLE_HPP_

#include <stdlib.h>

namespace robotis
{
    namespace turtlebot3
    {
        constexpr uint8_t EEPROM = 1;
        constexpr uint8_t RAM = 2;

        constexpr uint8_t READ = 1;
        constexpr uint8_t READ_WRITE = 3;
        
        typedef struct
        {
            uint16_t addr;
            uint8_t memory;
            uint16_t length;
            uint8_t rw;
        } ControlItem;

        typedef struct
        {
            ControlItem model_number = {0, EEPROM, 2, READ};
            ControlItem model_information = {2, EEPROM, 4, READ};
            ControlItem firmware_version = {6, EEPROM, 1, READ};

            ControlItem profile_acceleration_left = {174, RAM, 4, READ_WRITE};
            ControlItem profile_acceleration_right = {178, RAM, 4, READ_WRITE};
        } ControlTable;

        const ControlTable extern_control_table;
    }
}
#endif
