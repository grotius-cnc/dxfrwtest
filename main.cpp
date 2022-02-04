#include <iostream>
#include "libdxfrw.h"
#include "ExampleWriter.h"

using namespace std;

    int main()
    {
        dxfRW dxf("file.dxf");
        //! Subclassing. Not doing other stuff.
        ExampleWriter writer(dxf);

        //! Fill up the subclassed "writer" with data.
        DRW_Line line;
        line.basePoint.x = 10.20;
        line.basePoint.y = 20.10;
        line.secPoint.x = 30.25;
        line.secPoint.y = 30;
        writer.linevec.push_back(line);

        //! Here it will write all data at once to the dxf file.
        dxf.write(&writer, DRW::Version::AC1027, false);
        return 0;
    }

