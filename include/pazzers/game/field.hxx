
#ifndef PAZZERS_GAME_FIELD_HXX
#define PAZZERS_GAME_FIELD_HXX

namespace pazzers
{
    namespace game
    {
        class Field;
    }
}

#include <pazzers/game/cell.hxx>
#include <pazzers/geometry/xy.hxx>
#include <pazzers/resources/field-descriptor.hxx>
#include <pazzers/resources/image.hxx>

namespace pazzers
{
    namespace game
    {
        /**
         * \brief Represent a field for a single game.
         * */
        class Field
        {
        public:
            /**
             * \brief The width of the field.
             * */
            const int width;

            /**
             * \brief The height of the field.
             * */
            const int height;

            /**
             * \brief The number of total cells.
             * */
            const int total_cells;

            /**
             * \brief Create a new field using the specified descriptor.
             * \param fieldDescriptor The field's descriptor.
             * */
            Field(const resources::FieldDescriptor& fieldDescriptor);

            /**
             * \brief Release the used resources.
             * */
            virtual ~Field();

            /**
             * \brief Return the cell at a specified position.
             * \param position The specific position.
             * \return The cell at the specified position, or nullptr if the cell does not exists (also if position
             *     is not a valid one).
             */
            Cell* get_cell(const XY& position);

            /**
             * \brief Return a vector containing "n" random spawnable positiions.
             * \param n The number of random positions.
             * \return A vector with spawn positions.
             * */
            std::vector<XY> get_spawn_positions(int n);

            /**
             * \brief Draw the field.
             * \param position Where to draw the field on the screen.
             * */
            void draw(XY position);

        private:
            /**
             * \brief The array that contains all the field's cells.
             *
             * Cells are contained row by row.
             * */
            Cell** const all_cells;

            /**
             * \brief The two-dimensional array that contains all the field's cells.
             * */
            Cell*** const cells;

            /**
             * \brief The vector that contains all the spawnable positions.
             * */
            std::vector<XY> spawnable_positions;

            /**
             * \brief The image containing the whole field.
             * */
            resources::Image* image;

        };
    }
}

#endif
