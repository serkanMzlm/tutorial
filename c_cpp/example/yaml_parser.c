#include <stdio.h>
#include <yaml.h>

void process_node(yaml_parser_t *parser, int depth);

int main()
{
    char *file_path = "test.yaml";
    FILE *source = fopen(file_path, "rb");

    if (!source)
    {
        perror("Error opening file");
        return 1;
    }

    yaml_parser_t parser;
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, source);

    process_node(&parser, 0);

    yaml_parser_delete(&parser);
    fclose(source);

    return 0;
}

void process_node(yaml_parser_t *parser, int depth)
{
    yaml_event_t event;
    int storage = 0; // 0 for key, 1 for value

    while (1)
    {
        yaml_parser_parse(parser, &event);

        if (event.type == YAML_SCALAR_EVENT)
        {
            printf("%*s- %s: ", depth * 2, "", event.data.scalar.value);
            storage = 1;
        }
        else if (event.type == YAML_SEQUENCE_START_EVENT)
        {
            process_node(parser, depth + 1);
        }
        else if (event.type == YAML_SEQUENCE_END_EVENT)
        {
            break;
        }
        else if (event.type == YAML_SCALAR_EVENT && storage)
        {
            printf("%s\n", event.data.scalar.value);
            storage = 0;
        }

        yaml_event_delete(&event);
    }
}
