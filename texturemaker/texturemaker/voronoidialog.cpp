#include "voronoidialog.h"
#include "ui_voronoidialog.h"

//-----------------------------------------------------

VoronoiDialog::VoronoiDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::VoronoiDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->set_window_properties();

  parameters = this->block->get_parameters();

  ui->number_of_points->setValue(parameters->get_int_value("number of points"));
  ui->initial_x->setValue(parameters->get_double_value("initial x"));
  ui->initial_y->setValue(parameters->get_double_value("initial y"));
  ui->initial_angle->setValue(parameters->get_int_value("initial angle"));
  ui->radius->setValue(parameters->get_int_value("width"));
  ui->width->setValue(parameters->get_int_value("width"));
  ui->length1->setValue(parameters->get_int_value("width"));
  ui->length2->setValue(parameters->get_int_value("width"));
  ui->point_editor->set_points(parameters->get_string_value("point positions"));

  switch (parameters->get_int_value("point place"))
    {
      case PLACE_RANDOM:
        ui->radio_random->setChecked(true);
        break;

      case PLACE_SQUARE:
        ui->radio_square->setChecked(true);
        break;

      case PLACE_CIRCLE:
        ui->radio_circle->setChecked(true);
        break;

      case PLACE_CROSS_DIAGONAL:
        ui->radio_cross_diagonal->setChecked(true);
        break;

      case PLACE_CROSS_HORIZONTAL:
        ui->radio_cross_horizontal->setChecked(true);
        break;

      case PLACE_CUSTOM:
        ui->radio_custom->setChecked(true);
        break;
    }

  switch (parameters->get_int_value("type"))
    {
      case VORONOI_DISTANCE:
        ui->voronoi_type->setCurrentIndex(0);
        break;

      case VORONOI_2_NEAREST_RATIO:
        ui->voronoi_type->setCurrentIndex(1);
        break;
    }

  switch (parameters->get_int_value("metric"))
    {
      case METRIC_EUCLIDEAN:
        ui->voronoi_metric->setCurrentIndex(0);
        break;

      case METRIC_TAXICAB:
        ui->voronoi_metric->setCurrentIndex(1);
        break;

      case METRIC_CHEBYSHEV:
        ui->voronoi_metric->setCurrentIndex(2);
        break;
    }
}

//-----------------------------------------------------

VoronoiDialog::~VoronoiDialog()

{
  delete ui;
}

//-----------------------------------------------------

void VoronoiDialog::on_clear_button_clicked()

{
  ui->point_editor->clear();
}

//-----------------------------------------------------

void VoronoiDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;
  unsigned int i;
  int x,y;
  double float_points[MAXIMUM_POINTS][2];

  parameters = this->block->get_parameters();

  switch (ui->voronoi_type->currentIndex())
    {
      case 0:
        parameters->set_int_value("type",VORONOI_DISTANCE);
        break;

      case 1:
        parameters->set_int_value("type",VORONOI_2_NEAREST_RATIO);
        break;
    }

  switch (ui->voronoi_metric->currentIndex())
    {
      case 0:
        parameters->set_int_value("metric",METRIC_EUCLIDEAN);
        break;

      case 1:
        parameters->set_int_value("metric",METRIC_TAXICAB);
        break;

      case 2:
        parameters->set_int_value("metric",METRIC_CHEBYSHEV);
        break;
    }

  if (ui->radio_random->isChecked())
    parameters->set_int_value("point place",PLACE_RANDOM);
  else if (ui->radio_circle->isChecked())
    {
      parameters->set_int_value("point place",PLACE_CIRCLE);
      parameters->set_int_value("width",ui->radius->value());
    }
  else if (ui->radio_square->isChecked())
    {
      parameters->set_int_value("point place",PLACE_SQUARE);
      parameters->set_int_value("width",ui->width->value());
    }
  else if (ui->radio_cross_diagonal->isChecked())
    {
      parameters->set_int_value("point place",PLACE_CROSS_DIAGONAL);
      parameters->set_int_value("width",ui->length2->value());
    }
  else if (ui->radio_cross_horizontal->isChecked())
    {
      parameters->set_int_value("point place",PLACE_CROSS_HORIZONTAL);
      parameters->set_int_value("width",ui->length1->value());
    }
  else if (ui->radio_custom->isChecked())
    parameters->set_int_value("point place",PLACE_CUSTOM);

  parameters->set_int_value("number of points",ui->number_of_points->value());
  parameters->set_double_value("initial x",ui->initial_x->value());
  parameters->set_double_value("initial y",ui->initial_y->value());
  parameters->set_int_value("initial angle",ui->initial_angle->value());

  for (i = 0; i < ui->point_editor->get_number_of_points(); i++)
    {
      ui->point_editor->get_point(i,&x,&y);

      float_points[i][0] = x / ((double) ui->point_editor->width());
      float_points[i][1] = y / ((double) ui->point_editor->height());
    }

  parameters->set_string_value("point positions",c_texture_graph::coordinations_to_string(float_points,ui->point_editor->get_number_of_points()));
}

//-----------------------------------------------------
