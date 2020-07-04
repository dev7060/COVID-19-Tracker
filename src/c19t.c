#include <stdio.h>
#include "json.h"

int main(int argc, char **argv) {
	FILE *fp;
	char buffer[50000];
	struct json_object *parsed_json, *positive, *negative, *pending, *hospitalizedCurrently, *hospitalizedCumulative, *inIcuCurrently, *inIcuCumulative, *onVentilatorCurrently;
	struct json_object *onVentilatorCumulative, *recovered, *hash, *lastModified, *death, *hospitalized;
	struct json_object *total, *totalTestResults, *posNeg, *notes;
	FILE *fp1;
	FILE *fp2 = fopen("rd.json", "w");
	char ch;
	system("title COVID-19 Tracker by github.com/dev7060");
	system("COLOR 0A");
	printf("Fetching the latest data . . . \n");
	printf("_________________________________________________________________________________\n");
	system("curl https://covidtracking.com/api/v1/us/current.json > dwb.json");
	fp1 = fopen("dwb.json", "r");
	while((ch=fgetc(fp1))!=EOF){
		if(ch!='['&&ch!=']'){
			fputc(ch, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fp = fopen("rd.json","r");
	fread(buffer, 50000, 1, fp);
	fclose(fp);
	system("del rd.json");
	system("del dwb.json");
	parsed_json = json_tokener_parse(buffer);
	json_object_object_get_ex(parsed_json, "positive", &positive);
	json_object_object_get_ex(parsed_json, "negative", &negative);
	json_object_object_get_ex(parsed_json, "pending", &pending);
	json_object_object_get_ex(parsed_json, "hospitalizedCurrently", &hospitalizedCurrently);
	json_object_object_get_ex(parsed_json, "hospitalizedCumulative", &hospitalizedCumulative);
	json_object_object_get_ex(parsed_json, "inIcuCurrently", &inIcuCurrently);
	json_object_object_get_ex(parsed_json, "inIcuCumulative", &inIcuCumulative);
	json_object_object_get_ex(parsed_json, "onVentilatorCurrently", &onVentilatorCurrently);
	json_object_object_get_ex(parsed_json, "onVentilatorCumulative", &onVentilatorCumulative);
	json_object_object_get_ex(parsed_json, "recovered", &recovered);
	json_object_object_get_ex(parsed_json, "hash", &hash);
	json_object_object_get_ex(parsed_json, "lastModified", &lastModified);
	json_object_object_get_ex(parsed_json, "death", &death);
	json_object_object_get_ex(parsed_json, "hospitalized", &hospitalized);
	json_object_object_get_ex(parsed_json, "total", &total);
	json_object_object_get_ex(parsed_json, "totalTestResults", &totalTestResults);
	json_object_object_get_ex(parsed_json, "posNeg", &posNeg);
	json_object_object_get_ex(parsed_json, "notes", &notes);
	printf("_________________________________________________________________________________\n");
	printf("United States of America\n");
	printf("_________________________________________________________________________________\n");
	printf("Positive: %d\n", json_object_get_int(positive));
	printf("Negative: %d\n", json_object_get_int(negative));
	printf("Pending: %d\n", json_object_get_int(pending));
	printf("Hospitalized Currently: %d\n", json_object_get_int(hospitalizedCurrently));
	printf("Hospitalized Cumulative: %d\n", json_object_get_int(hospitalizedCumulative));
	printf("In Icu Currently: %d\n", json_object_get_int(inIcuCurrently));
	printf("In Icu Cumulative: %d\n", json_object_get_int(inIcuCumulative));
	printf("On Ventilator Currently: %d\n", json_object_get_int(onVentilatorCurrently));
	printf("On Ventilator Cumulative: %d\n", json_object_get_int(onVentilatorCumulative));
	printf("Recovered: %d\n", json_object_get_int(recovered));
	//printf("hash: %s\n", json_object_get_string(hash));
	//printf("lastModified: %d\n", json_object_get_string(lastModified));
	//printf("death: %d\n", json_object_get_int(death));
	//printf("hospitalized: %d\n", json_object_get_int(hospitalized));
	//printf("total: %d\n", json_object_get_int(total));
	//printf("totalTestResults: %d\n", json_object_get_int(totalTestResults));
	//printf("posNeg: %d\n", json_object_get_int(posNeg));
	//printf("notes: %s\n", json_object_get_string(notes));
	printf("_________________________________________________________________________________\n");
	system("pause");
}
